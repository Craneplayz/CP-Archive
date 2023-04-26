using System;
using System.Collections.Generic;

class Program{
    static void solve(){
        var dict = new Dictionary<char, int>();
        var list = new int[] {0, 0, 0, 0};
        int index = 0;
        var x = Console.ReadLine();
        for (int i = 0; i < 4; i++)
        {
            var xc = Convert.ToChar(x[i]);
            if (dict.ContainsKey(xc))
                list[dict[xc]]++;
            else
            {
                dict[xc] = index++;
                list[dict[xc]]++;
            }
        }
        Array.Sort<int>(list, new Comparison<int>(
            (a, b) => b.CompareTo(a))
        );

        if (dict.Count >= 3){
            Console.WriteLine("4");
        }
        else if (dict.Count == 2){
            if (list[0] == 2) Console.WriteLine("4");
            else Console.WriteLine("6");
        }
        else Console.WriteLine("-1");
    }
    static void Main(){
        var input = Console.ReadLine();
        var t = Convert.ToInt32(input);
        for (int i = 0; i < t; i++){
            solve();
        }
    }
}