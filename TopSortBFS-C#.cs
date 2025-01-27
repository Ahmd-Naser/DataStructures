private int[] topSort(int n , int[][] adjList ){

        int[] inDegree = new int[n];
        int[] Level = new int[n];

        foreach(var i in adjList){
            inDegree[i[1] ]++;
        }


        Queue<int> q = new();

        for(int i = 0 ; i<n; i++){
            if(inDegree[i] == 0 )
                q.Enqueue(i);

        }

        int level = 0;

        while(q.Count > 0){
            int sz = q.Count ;

            while(sz-- > 0){
                int node = q.Dequeue();
                Level[node] = level;

                foreach(var i in graph[node] ){
                    inDegree[i]--;

                    if(inDegree[i] == 0)
                        q.Enqueue(i);
                }
            }

            level++;
        }

        return Level;
    }