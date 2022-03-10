package com.metanit;

public class Main {

    public static void main(String[] args) {
        String[] Pokemons = new String[]{"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};
        int LengthLines = 7;
        int Matches=0;
        String Word = "va......";
        String[] SplitedWord = Word.replace(".","").split("");
 for (int i=0;i< Pokemons.length;i++)
       {
           for (int k=0;k< SplitedWord.length;k++) {
             if (Pokemons[i].contains(SplitedWord[k]))
            {
                Matches++;
                  if(Matches==SplitedWord.length)
                  {
                     System.out.println(Pokemons[i]);
                  }
               }
           }
     }
   }
}


