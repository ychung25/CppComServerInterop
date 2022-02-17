using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using SpotifyInterface;

namespace CSClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("C# COM client playing spotify from a main thread\n");
            Spotify spotify = new Spotify();
            spotify.Play();
        }
    }
}
