 /* 
   Computer Networks Laboratory (Lab) 15CSL77
   10. Write a program for congestion control using Leaky bucket algorithm.
 */

 /* Network layer
    
    Varialbe traffic rate

    Match rate of output link/line

    Remove burstiness or jitter
 */

 /* MTU (Maximum Transmission Unit) for Ethernet is 1500 bytes.
 */

 /* The leaky bucket consists of a finite queue 

    When a packet arrives, 
      if there is room on the queue it is appended to the queue; 
      otherwise it is discarded

    At every clock tick one packet is transmitted (unless the queue is empty)
 */

 /*
    Router A to B
    A has queue so link to B does not get congested
    A is restricting its output

    A sends, fails, retries, instead match the capacity of A to B link

    A limits to match B
 */
 
 /* Queue, enqueue, dequeue, isFull
    Circular queue
 */

 /* Read parameters of the bucket:

    1. Read Bucket(Queue) Size, bucketSize or queueSize
       Size in terms of packets it can hold

    2. Read output rate, bucketRate
       In terms of packets Sent/output(dequeued) from bucket(queue)    


    Read number of times to simulate, time

    for t  ← 0 to time

      Simulate flow into bucket, incoming traffic
      
      Read number of incoming packets, numberOfIncomingPackets

      Read content of incoming packets, contentOfIncomingPacket[]

      Now add to bucket

      for packet p in numberOfIncomingPackets

         if bucket(queue) not full
           enqueue( contentOfIncomingPacket[p] )

         else
           packet p discarded

      Adding to bucket complete, now simulate flow out of bucket
      
      Leaky bucket

      for  t  ← 0 to bucketRate
        outgoingPacket = dequeue( contentOfIncomingPacket )
        print outgoingPacket
    
 */

 /* Textbook: 
    Behrouz Forouzon - Data Communications and Networking, McGraw Hill Edition 
    Andrew S. Tanenbaum - Computer Networks
 */
