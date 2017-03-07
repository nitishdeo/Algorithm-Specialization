import java.io.*;
import java.util.*;
import java.lang.System;
class PSet{
    HashSet<ArrayList<Integer>> setObj;
}
class TSP {
    public static double dist[][] = new double[30][30];
    public static int subsetCnt = 0; 
    public static double INF = 99999999.0;
    public static HashMap<String,Integer> hm = new HashMap<String,Integer>();
    //Function for powerset
    public static PSet[] getPowerSet(ArrayList<Integer> newList){
        //variables
        int sizeOfList=newList.size();
        ArrayList<Integer> temp;
        PSet powerSet[] = new PSet[sizeOfList+1];
        Stack<ArrayList<Integer>> stk = new Stack<ArrayList<Integer>>();
        //Object space declaration
        for(int i=0;i<=sizeOfList;i++){
            powerSet[i] = new PSet();
            powerSet[i].setObj=new HashSet<ArrayList<Integer>>();
        }
        //Push the first element into stack
        stk.push(newList);
        //Loop while stack is not empty
        while(!stk.isEmpty()){
            newList = stk.pop();
            sizeOfList = newList.size();
            if(sizeOfList>0 && newList.get(0)==1){
                powerSet[sizeOfList].setObj.add(newList);
                //Remove each element of newList once and add it to stack
                //Here starting from 1 to avoid those sub sets, which does not contain 1, to be pushed into stack
                for(int i=1;i<sizeOfList;i++){
                    temp = new ArrayList<Integer>(newList);
                    temp.remove(i);
                    stk.push(temp);
                }
            }
        }
        sizeOfList=powerSet.length;
        for(int i=1;i<sizeOfList;i++){
        	for(ArrayList<Integer> arrList: powerSet[i].setObj){
        		subsetCnt++;
        		hm.put(arrList.toString(), subsetCnt);
        	}
        }
        return powerSet;
    }
    //Entry Point
    public static void main(String args[])throws Exception{
        System.setIn(new FileInputStream("tsp.txt"));
        System.setOut(new PrintStream(new FileOutputStream("Result.txt")));
        System.setErr(new PrintStream(new FileOutputStream("ResErr.txt")));
        Scanner sc = new Scanner(System.in);
        
        int N;
        double xDiff,yDiff;
        N = sc.nextInt();//Number of vertices
        double coord[][]=new double[N+1][2];
        
        //Creating distance matrix
        for(int i=0;i<N;i++){
            coord[i][0] = sc.nextDouble();
            coord[i][1] = sc.nextDouble();
        }
        //Read the graph from file
        for(int i=1;i<=N;i++){
            for(int j=i;j<=N;j++){
                xDiff = coord[i][0]-coord[j][0];
                yDiff = coord[i][1]-coord[j][1];
                dist[i][j] = Math.sqrt(xDiff*xDiff + yDiff*yDiff);
                dist[j][i] = dist[i][j];
            }
        }
        sc.close();
        //Set the newList
        //N=5;//5;
        ArrayList<Integer> newList = new ArrayList<Integer>();
        for(int i=1;i<=N;i++){
            newList.add(i);
        }
        //Create the PowerSet
        PSet powerSet[]=getPowerSet(newList);
        //Declare the workspace matrix work to save A[S,k]
        //where S is subset and k is the ending vertex
        double work[][] = new double[subsetCnt+1][N+1];
        //initialise the matrix
        for(int i=1;i<=subsetCnt;i++){
        	for(int j=1;j<=N;j++){
        		work[i][j] = INF;
        	}
        }
        work[1][1]=0;
        //Run the main loop
        double minDist = INF;
        double temp = INF;
        ArrayList<Integer> tempList;
        for(int i=1;i<=N;i++){
            for(ArrayList<Integer> arrList: powerSet[i].setObj){
            	for(Integer j:arrList){
            		if(j!= 1){
            			minDist = INF;
            			temp = INF;
            			for(Integer k:arrList){
            				if(k!=j){
            					tempList = new ArrayList<Integer>(arrList);
            					tempList.remove(j);
            					temp = work[hm.get(tempList.toString())][k]+dist[k][j];
            					if(minDist>temp){
            						minDist = temp;
            					}
            				}
            			}
            			work[hm.get(arrList.toString())][j] = minDist;
            		}
            	}
            }
        }
        minDist = INF;
		temp = INF;
        for(int i=2;i<=N;i++){
        	temp = work[subsetCnt][i]+dist[i][1];
        	if(minDist>temp){
				minDist = temp;
			}
        }
        System.out.print("Distance of minimum distant tour = "+minDist);
    }
}