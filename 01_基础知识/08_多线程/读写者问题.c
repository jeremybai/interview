//读者优先
/**
   1、首先当读者获得临界区的访问权，则此时的readcount  > 0 则读者尚未释放fmutex则写者就不能获得临界区的访问权，有一个被阻塞在fumtex信号中，其余的被塞    在Entmutex信号中，则只有当读者访问完毕，写者才有机会获得临界区的访问权

  2、若写者获得临界区的访问权，而且有源源不断的写着进程过来，那么读者能不能抢得临界区的访问权呢？答案是肯定的，因为考虑此时的读者进程阻塞情况，有一个读者进程阻塞在fmutex中，其余的读者均阻塞在Rmutex，而写者进程呢，由于Entemutex的存在每个时刻只有一个一个写者进程阻塞在fmutex中，其余的全被阻塞在Entmutex中，则当写者进程访问完毕后，此时阻塞在fmutex中的进程只有读者进程，则也就只有读者进程先被激活访问
*/

mutex = 1    //读者、写者进程访问文件信号量变量，保证了读者与写者、写者与写者之间的互斥访问
Rmutex = 1   //实现对readcount的互斥访问
Entmutex =1  //若写者获得临界区的访问权，而且不断有写者进程过来，
             //那么读者将不能抢得临界区的访问权
readcount = 0
Read()
{
    while(1)
    {
        wait(Rmutex) ;
        if(0 == readcount)
            wait(mutex) ;
        readcount ++ ;
        signal(Rmutex) ;
        -----------------------------
        | perform reading operation |
        -----------------------------
        wait(Rmutex);
        readcount --;
        if(0 == readcount)
            signal(mutex)
        signal(Rmutex) ;

    }
}
Writer()
{
    while(1)
    {
		//保证每次阻塞在mutex中的写者进程只有一个，
		//确保当前写者写完，若还有写者等待，则会被卡在Entmutex，读者不需要等待
		wait(Entmutex)
        wait(mutex)
        -----------------------------
        | perform writing operation |
        -----------------------------
        signal(mutex)
		signal(Entmutex)
    }
}




//写者优先
/**
1.当读者获得了访问临界区的权利时，且读者进程访问的很密集时(即很多读者都需要访问)，写者如何抢得访问权。

由于Entmutex的存在每次阻塞在Quemutex中的读者进程最多只有一个，而当读者进程访问时，写着进程一个被阻塞在Quemutex中，其余的全部阻塞在Wcount中，当读者访问完毕，释放Quemutex，此时，阻塞在其中的进程只有写者进程，则写着进程得到激活

2.当写者获得临界区的访问权时，读者只能等到临界区空闲时才能得到临界区访问权。

因为当写者获得临界区时，所有的读者都会阻塞在Entmutex信号和QUemutex信号中。 而只有最后一个写者访问完临界区时，才会Signal(Qmutex)， 使得阻塞在fmutex中唯一的读者获得临界区访问权。

*/
Entemutex = 1
Quemutex = 1
Rmutex = 1
Wmutex = 1
mutex = 1 
readcount = 0

Reader()
{
    while(1)
    {
        wait(Entemutex)
        wait(Quemutex)

        wait(Rmutex)
        if(0 == readcount)
            wait(mutex)
        readcount++
        signal(Rmutex)

        signal(Quemutex)
        signal(Entemutex)
        -----------------------------
        | perform reading operation |
        -----------------------------
        wait(Rmutex)
		readcount--
        if(readcount == 0)
            signal(mutex)
        signal(Rmutex)
    }
}
writer()
{
    while(1)
    {
        wait(Wmutex)
        if(writecount == 0)
            wait(Quemutex)
        writecount++
        signal(Wmutex)
		
        wait(mutex)
        -----------------------------
        | perform writing operation |
        -----------------------------
        signal(mutex)

        wait(Wmutex)
        writecount--
        if(writecount == 0)
            signal(Quemutex)
        signal(Wmutex)

    }
}


//公平竞争
Reader()
{
    while(1)
    {
        wait(Quemutex)

        wait(Rmutex)
        if(0 == readcount)
            wait(mutex)
        readcount++
        signal(Rmutex)

        signal(Quemutex)

        -----------------------------
        | perform reading operation |
        -----------------------------

        wait(Rmutex)
		readcount--
        if(readcount == 0)
            signal(mutex)
        signal(Rmutex)
    }
}

writer()
{
    while(1)
    {
        wait(Quemutex)

        wait(mutex)
        -----------------------------
        | perform writing operation |
        -----------------------------
        signal(mutex)
        
        signal(Quemutex)

        

    }
}
