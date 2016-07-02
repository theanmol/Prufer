/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author deexita
 */
import java.util.*;
public class PruferCode {
    public  List<Integer>[] pruferCode2Tree(int[] pruferCode)
    {
        int n = pruferCode.length + 2;  //number of vertices in the tree
        
        List<Integer>[] tree = new List[n];     //adjacency list of tree(array of list)
        for (int i = 0; i < n; i++)
            tree[i] = new ArrayList<>();        //initializing each list for each vertex
        int[] degree = new int[n];              //declaring array to store degree of each vertex
        Arrays.fill(degree, 1);                 //initializing with 1
        for (int v : pruferCode)
            ++degree[v]; 
       //calculating the degree of each vertex
       
      
       int ptr = 0;
        while (degree[ptr] != 1)                //finding the first vertex with degree 1 (1st leaf node)
            ++ptr;
        int leaf = ptr;
        for (int v : pruferCode)
        {
            tree[leaf].add(v);                  //adding edge between leaf node and its neighbour
            tree[v].add(leaf);                  //vice versa
            --degree[leaf];                     //subtracting degree by 1 for both nodes
            --degree[v];
            if (degree[v] == 1 && v < ptr)      //checking either v is leaf node or not
            {
                leaf = v;
            }
            else                                //finding next leaf node
            {
                for (++ptr; ptr < n && degree[ptr] != 1; ++ptr)
                    ;
                leaf = ptr;                 //ptr is the next leaf node to be added in the tree
            }
        }
        for (int v = 0; v < n - 1; v++)         //adding last edge between largest vertex and the emaining vertex with degree 1
        {
            if (degree[v] == 1)
            {
                tree[v].add(n - 1);
                tree[n - 1].add(v);
            }
        }
        return tree;
    }
    static void pruferDfs(List<Integer>[] tree, int[] parent, int v)
    {
        for (int i = 0; i < tree[v].size(); ++i)
        {
            int to = tree[v].get(i);
            if (to != parent[v])
            {
                parent[to] = v;
                pruferDfs(tree, parent, to);
            }
        }
    }
    public int[] tree2PruferCode(List<Integer>[] tree)
    {
        int n = tree.length;
        int[] parent = new int[n];
        parent[n - 1] = -1;
        pruferDfs(tree, parent, n - 1);
        int[] degree = new int[n];
        int ptr = -1;
        for (int i = 0; i < n; ++i)
        {
            degree[i] = tree[i].size();
            if (degree[i] == 1 && ptr == -1)
                ptr = i;
        }
        int[] res = new int[n - 2];
        int leaf = ptr;
        for (int i = 0; i < n - 2; ++i)
        {
            int next = parent[leaf];
            res[i] = next;
            --degree[next];
            if (degree[next] == 1 && next < ptr)
            {
                leaf = next;
            }
            else
            {
                ++ptr;
                while (ptr < n && degree[ptr] != 1)
                    ++ptr;
                leaf = ptr;
            }
        }
        return res;
    }
    
}
