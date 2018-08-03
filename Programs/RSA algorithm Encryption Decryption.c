/* 
	Computer Networks Laboratory (Lab) 15CSL77
	9. Write a program for simple RSA algorithm to encrypt and decrypt the data.
*/

/*  RSA ( Ron Rivest, Adi Shamir, and Leonard Adleman) asymmetric Public Key cryptography algorithm
    
    Asymmetric - Two keys, one key is public other private

    Cryptography - Encryption algorithm

    Based on the practical difficulty of the factorization of the product of 
    two large prime numbers, the "factoring problem"

    Integer factorization is the decomposition of a composite number into a product of smaller integers
    If only prime numbers are used, the process is called prime factorization
 
    Publish a public key based on two large prime numbers

    Prime numbers must be kept secret. Anyone can use the public key to encrypt a message.

    Only someone with knowledge of the prime numbers can decode the message feasibly
*/

/*  Generating Public Key
    1. Choose two distinct prime numbers, p, and q
    2. Compute n = p*q 
    3. Compute the totient of the product as λ(n) = (p − 1) * (q − 1)
       λ(n) can also be, λ(n) = lcm(λ(p), λ(q)) = lcm(p − 1, q − 1)
    4. Choose any number 1 < e < λ(n) that is coprime to λ(n)
       e

    Coprime, two integers a and b are said to be relatively, mutually or co prime 
      if the only positive integer (factor) that divides both of them is 1
    a, and b need not be prime. Example 14, 15

    ( n , e )  is the Public key

    5. Compute d, the modular multiplicative inverse of e (mod λ(n)) 
       Inverse
       Multiplicative
       Modular
       d * e mod λ(n) = 1 
    
    ( n , d )  is the Private key
*/

/* To encrypt, Cipher c, for message m
   c = ( m power e ) mod n
*/ 

/* To decrypt, 
   m = ( c power d ) mod n
*/


/* For two numbers m, n 
   lcm = m * n / gcd  
   Computes gcd by Euclid’s algorithm
*/

// ALGORITHM Euclid(m, n)
//   Computes gcd(m, n) by Euclid’s algorithm
//   Input: Two nonnegative, not-both-zero integers m and n
//   Output: Greatest common divisor of m and n
//   while n != 0 
//     do
//       r ← m mod n
//       m ← n
//       n ← r
//     done 
//   return m

int euclidsAlgorithm(int m , int n )
 {
   int r = 0;

   char temp; 
   
   printf("\n Euclid's Algorithm \n");
   printf("\n r = %d \t m = %d \t n = %d \n", r, m, n);

   while( n!=0 )
    {
      r = m % n;
      m = n;
      n = r;
      printf("\n r = %d \t m = %d \t n = %d \n", r, m, n);
    }

   printf("\n Algorithm complete \n GCD to be returned GCD = %d", m );
   return m;
 }

/*
   Read p, q
   
*/

/* p = 13
   q = 17
   n = p * q = 13 * 17 = 221

   λ(n) = ( p - 1 ) * ( q - 1 ) = 12*16 = 192

   e, such that, 1 < e < λ(n) and coprime to λ(n)

   e = 35

   ( n , e ) is Public key. ( 221 , 35 )

   d * e mod λ(n) = 1
 
   d * 35 mod 192 = 1

   11 * 35 mod 192 =  1

   ( n , d ) is Private key. ( 221 , 11 )  
*/

/* To encrypt, Cipher c, for message m
   c = ( m power e ) mod n
   Suppose, m = 123
   c = ( m power 35 ) mod 221

   c = 1 power 35 mod 221 = 1
   c = 2 power 35 mod 221 = 59
   c = 3 power 35 mode 221 = 61

   c = 1 59 61
*/ 

/* To decrypt, 
   m = ( c power d ) mod n

   m = ( c power 11 ) mod 221

   c = 1 59 61

   1 = ( 1 power 11 ) mod 221
   2 = ( 59 power 11 ) mod 221
   3 = ( 61 power 11 ) mod 221
*/

/* p = 3
   q = 11
   e = 3
   d = 7
   n = 33
   

*/

/* Textbook: Behrouz Forouzon - Data Communications and Networking, McGraw Hill Edition 
             Algorithms
*/
