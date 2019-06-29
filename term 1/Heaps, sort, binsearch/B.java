mport javafx.util.Pair;


import java.io.File;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;


public class B {
    public static void main(String[] args) throws IOException {

        class MinHeap {
            public ArrayList<Pair<Integer, Integer>> heap;

            MinHeap(ArrayList<Pair<Integer, Integer>> a) {
                heap = a;
            }

            public void siftDown(int i) {
                while (2 * i + 1 < heap.size()) {
                    int left = 2 * i + 1;
                    int right = 2 * i + 2;
                    int j = left;

                    if ((right < heap.size()) && ((heap.get(right).getValue()) < (heap.get(left).getValue()))) {
                        j = right;
                    }

                    if ((heap.get(i).getValue()) <= (heap.get(j).getValue())) {
                        break;
                    }
                    Pair t = heap.get(i);
                    heap.set(i, heap.get(j));
                    heap.set(j, t);
                    i = j;
                }
            }

            public void siftUp(int i) {
                while ((heap.get(i).getValue()) < heap.get((i - 1) / 2).getValue()) {
                    Pair t = heap.get(i);
                    heap.set(i, heap.get((i - 1) / 2));
                    heap.set((i - 1) / 2, t);
                    i = (i - 1) / 2;
                }
            }

            public Pair extractMin() {
                Pair min = heap.get(0);
                heap.set(0, heap.get(heap.size() - 1));
                heap.remove((heap.size() - 1));
                siftDown(0);
                return min;
            }

            public void insert(Pair k) {
                heap.add(k);
                siftUp((heap.size() - 1));
            }
        }


        MinHeap myheap = new MinHeap(new ArrayList<Pair<Integer, Integer>>());
        Scanner scanner = new Scanner(new File("priorityqueue.in"));
        FileWriter fileWriter = new FileWriter(new File("priorityqueue.out"));
        int count = 0;
        while (scanner.hasNextLine()) {
            String split[] = scanner.nextLine().split(" ");
            count++;
            switch (split[0].charAt(0)) {
                case 'p':
                    myheap.insert(new Pair<Integer, Integer>(count, Integer.parseInt(split[1])));
                    break;
                case 'e':
                    if (myheap.heap.size() < 1) {
                        fileWriter.write("*" + "\r\n");
                        fileWriter.flush();
                    } else {
                        fileWriter.write(myheap.extractMin().getValue() + "\r\n");
                        fileWriter.flush();
                    }
                    break;
                case 'd':
                    int num1 = Integer.parseInt(split[1]);
                    for (int i = 0; i < myheap.heap.size(); i++) {
                        if (myheap.heap.get(i).getKey() == num1) {
                            myheap.heap.set(i, new Pair<Integer, Integer>(num1, Integer.parseInt(split[2])));
                            myheap.siftUp(i);
                            break;
                        }
                    }
                    break;
            }
        }
    }
}


