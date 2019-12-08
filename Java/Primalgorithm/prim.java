import java.util.Scanner;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.PriorityQueue;

class A implements Comparable<A>{
	//start
	int s;
	//end
	int e;
	//weight
	int v;
	public A(int s, int e, int v){
		super();
		this.s = s;
		this.e = e;
		this.v = v;
	}
	@Override
	public int compareTo(A arg0){
		return arg0.v >= this.v ? -1 : 1;
	}
}
//prim function
public class prim {
	public static int find(int a){
		if(a==parent[a]) return a;
		parent[a] = find(parent[a]);
		return parent[a];
	}
	public static void union(int a, int b){
		int aRoot = find(a);
		int bRoot = find(b);
		if(aRoot != bRoot){
			parent[aRoot] = b;
		}
		else{
			return;
		}
	}

	//global variable
static int N;
static int E;
static PriorityQueue<A> pq;
static int[] parent;
static boolean[] visit;
static int result;

//main function
	public static void main(String[] args) throws Exception {
		Scanner scan = new Scanner(System.in);
		//input number of vertex
		N = scan.nextInt();
		//input number of edge
		E = scan.nextInt();
		
		parent = new int[N+1];
		visit = new boolean[N+1];
		result = 0;
		pq = new PriorityQueue<A>();
		int ta;
		int tb;
		int tc;
		for( int i =0;i<E;i++){
			//input start vertex
			ta = scan.nextInt();
			//input end vertex
			tb = scan.nextInt();
			//input weight
			tc = scan.nextInt();
			pq.add(new A(ta,tb,tc));
		}
		for(int i = 1; i<=N;i++){
			parent[i] = i;
		}
		for(int i = 0;i<E;i++){
			A oneNode = pq.poll();
			int start = oneNode.s;
			int end = oneNode.e;
			int a = find(start);
			int b = find(end);
			if(a==b) continue;
			union(start,end);
			result += oneNode.v;
		}
		//print output
		System.out.println(result);
	}
}
