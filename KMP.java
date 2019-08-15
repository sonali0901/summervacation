/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
class Codechef
{
	public static void main (String[] args) throws java.lang.Exception
	{
		String text = "HelloWorlMayIKnow";
		String pattern = "World";
		int preffixArray[] = new int[pattern.length()];
		int j =0;
		preffixArray[0] = 0;
		for(int i=1;i<pattern.length();i++){
		    if(pattern.charAt(i) == pattern.charAt(j)){
		        preffixArray[i] = j+1;
		        i++;
		        j++;
		    }
		    else{
		        if(j == 0) {
		            preffixArray[i] = 0;
		            i++;
		        }
		        else{
		            j = preffixArray[j-1];
		        }
		    }
		}
		
		int i;
		j =0; // text
		for(i =0;i<pattern.length() && j<text.length();)
		{
		    if(pattern.charAt(i)== text.charAt(j))
		    {
		        i++;j++;
		    } else {
		        if(i>0)
		         i = preffixArray[i-1];
		         else
		         j++;
		    }
		}
		if(i == pattern.length())
		{
		    System.out.println("Matches");
		}
		
	}
}
