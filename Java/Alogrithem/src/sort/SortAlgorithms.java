package sort;

import java.util.Arrays;
import java.util.Stack;

/**
 * 八大排序算法实现
 * 1. 直接插入排序  {@link #insertionSort}
 * 2. 希尔排序      {@link #shellSort}
 * 3. 简单选择排序  {@link #selectionSort}
 * 4. 堆排序        {@link #heapSort}
 * 5. 冒泡排序      {@link #bubbleSort}
 * 6. 快速排序      {@link #quickSort}
 * 7. 归并排序      {@link #mergingSort}
 * 8. 基数排序      {@link #radixSort}
 * <p>
 * 算法测试类见 {@link Test}
 * 算法评估分析类见 {@link Bench}
 */

public class SortAlgorithms {
    public static final boolean ENABLE_PRINT = true;

    public static void main(String[] args) {
        int[] array = new int[]{5, 3, 9, 1, 6, 4, 10, 2, 8, 7, 15, 3, 2};

        System.out.println("Before:" + Arrays.toString(array));
//        SortAlgorithms.insertionSort(array);
        SortAlgorithms.shellSort(array);
//        SortAlgorithms.heapSort(array);
//        SortAlgorithms.bubbleSort(array);
//        SortAlgorithms.quickSort(array,0,array.length-1);
//        SortAlgorithms.quickSortByStack(array);
//        SortAlgorithms.insertionSort(array);
//        SortAlgorithms.insertionSort(array);
//        System.out.println("After: " + Arrays.toString(array));
    }

    /**
     * 统一控制是否控制台输出
     */
    private static void System_out_println(String str) {
        if (ENABLE_PRINT) {
            System.out.println(str);
        }
    }

    public static void insertionSort(int[] arr) {
        /**
         * 普通插入排序
         **/
//        for (int i = 0; i < arr.length - 1; i++) {
//            for (int j = i + 1; j > 0; j--) {//【Err】此处j朝左走
//                if (arr[j - 1] <= arr[j]) break;
//                int temp = arr[j];      //交换操作,代价较大
//                arr[j] = arr[j - 1];      //【Err】此处为紧邻交换
//                arr[j - 1] = temp;
//                System_out_println("Sorting:" + Arrays.toString(arr));
//            }
//        }
        /**
         * 二分插入排序
         * */
        for (int i = 1; i < arr.length; i++) {
            int temp = arr[i];
            for (int j = i; j > 0; j--) {
                if (j > 0 && arr[j - 1] > temp) {//j-1处值大于末尾值，则向后退一格
                    arr[j] = arr[j - 1];
                } else {
                    arr[j] = temp;
                    break;
                }
            }
        }
    }

    /*****************************************************************************************
     * 希尔排序，也称递减增量排序算法，第一个突破O(n^2)的排序算法
     * step1：子序列直接插入排序
     * step2：待整个序列【基本有序】时，全体直插排序
     * 与插入排序不同在于：它会优先比较距离较远的元素
     */

    public static void shellSort(int[] arr) {
        /**
         * 希尔排序【粗糙易懂版】
         * 1.
         */
//        /** bei*/
//        int increment = arr.length / 2;
//        for (int i = 0; increment > 0; increment /= 2) {
//            for (int j = i; j < arr.length; j += increment) {
//                for (int k = j + increment; k > 0; k -= increment) {
//                    if (k < arr.length && arr[k - increment] <= arr[k]) break;//有序序列
//                    int temp = arr[k];
//                    arr[k] = arr[k - increment];
//                    arr[k - increment] = arr[k];
//                }
//            }
//        }
        /** iTimeTraveler*/
        int gap = arr.length / 2;
        for (; gap > 0; gap /= 2) {     //不断缩小gap,直到1为止
            System_out_println("Gap=" + gap);
            for (int j = 0; (j + gap) < arr.length; j++) {    //使用当前增量进行组内插入排序
                for (int k = 0; (k + gap) < arr.length; k += gap) {
                    if (arr[k] > arr[k + gap]) {
                        int temp = arr[k + gap];
                        arr[k + gap] = arr[k];
                        arr[k] = temp;
                        System_out_println("Sorting: " + Arrays.toString((arr)));
                    }
                }
            }
        }
    }

    /*****************************************************************************************
     * 希尔排序【Wiki官方版】
     *
     * 1.选择一个增量序列t1,t2,...,tk,其中ti>tj,tk=1; (注意此算法取值)
     * 2.按增量序列个数k，对序列进行k趟排序;
     * 3.每趟排序，根据对应的增量ti，将待排序列分割成若干长度为m的子序列，分别对各子表进行直接插排。
     *   仅增量因子为1时，整个序列作为一个表来处理，表长度即为整个序列的长度。
     * @param arr 待排序数组
     */
    public static void shell_Sort(int[] arr) {
        int gap = 1, i, j, len = arr.length;
        int temp;
        while (gap < len / 3)        //筛选合适的增量
            gap = gap * 3 + 1;        //<O(n^(3/2)) by Knuth>:1,4,13,40,121,...
        for (; gap > 0; gap /= 3) {
            for (i = gap; i < len; i++) {
                temp = arr[i];
                for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap)
                    arr[j + gap] = arr[j]; //前面大的往后挪，给temp把位置腾开
                arr[j + gap] = temp;
            }
        }
    }

    /*****************************************************************************************
     * 选择排序
     *
     * 1. 从待排序序列中，找到关键字最小的元素;
     * 2. 如果最小元素不是待排序列的第一个元素，将其和第一个元素互换;
     * 3. 从余下的 N - 1个元素中，找出关键字最小的元素，重复1，2步，直到排序结束；
     *    仅增量因子为1时，整个序列作为一个表来处理，表长度即为整个序列的长度
     * @param arr 待排序数组
     * */
    public static void selectionSort(int[] arr) {
        /** bei*/
//        for(int i=0;i<arr.length;i++){
//            int min=arr[i];
//            for(int j=i+1;j<arr.length;j++){
//                if(arr[j]<min){
//                    min=arr[j];
//                }
//            }
//            arr[i]=min;
//        }
        /** iTime*/
        for (int i = 0; i < arr.length - 1; i++) {
            int min = i;
            for (int j = i + 1; j < arr.length; j++) {
                if (arr[j] < arr[min]) {
                    min = j;
                }
            }
            if (min != i) {
                int temp = arr[min];
                arr[min] = arr[i];
                arr[i] = temp;
                System_out_println("Sorting: " + Arrays.toString(arr));
            }
            /**
             * 评价：简单、直观名副其实，但也造成它【出了名的慢性子】即便原数组已经有序，它也将花费(n^2/2)次重排一遍
             * 不稳定：若从后面无序集合中选出的最小值，和前面有序集合末尾数一样大，也还是要交换一次
             */
        }
    }


    /**
     * *************************************************************************************
     * 堆排序
     * 利用了完全二叉树中父节点与子节点的位置特征
     * 堆：完全二叉树中任何一个非叶子节点的值均不大/小于左右子节点
     * 核心操作：1.建堆 2.调整
     */

    public static void heapSort(int[] arr) {
        for (int i = arr.length; i > 0; i--) {
            adjustUp(arr, i);

            int temp = arr[0];
            arr[0] = arr[i - 1];
            arr[i - 1] = temp;
        }
        /** bei*/
        /** 加入新元素后调整堆*/
        //if (arr[len - 1] <)

    }

    public static void adjustUp(int[] arr, int limit) {
        /** bei*/
//        int len = arr.length;
//        for (int i = len - 1; i >= 0; i--) {      //建堆
//            for (int  j= len / 2; j >= 0; j /= 2) {
        //缺少判断最大子节点的步骤
//                if (arr[j] > arr[i]) {
//                    int temp = arr[i];    //把大子往上挪
//                    arr[i] = arr[j];
//                    arr[j] = temp;
//                }
//            }
//            int temp = arr[len - 1];    //交换堆顶、堆末元素
//            arr[len - 1] = arr[0];
//            arr[0] = arr[len - 1];
//        }
        /** iTimeTraveler*/
        if (arr.length <= 0 || arr.length < limit) return;
        int parentIdx = limit / 2;
        for (; parentIdx >= 0; parentIdx--) {
            if (parentIdx * 2 >= limit) {
                continue;
            }
            int left = parentIdx * 2;      //左子节点位置
            int right = (left + 1) >= limit ? left : (left + 1);     //右子节点位置

            int maxChildId = arr[left] >= arr[right] ? left : right;
            if (arr[maxChildId] > arr[parentIdx]) {     //把大子往上挪
                int temp = arr[parentIdx];
                arr[parentIdx] = arr[maxChildId];
                arr[maxChildId] = temp;
            }
            System_out_println("Max_Heapify:" + Arrays.toString(arr));
        }

    }
    /**
     * 评价：由于堆排序中初始化堆的过程比较次数较多，因此他不适用于小序列
     * 建堆用时O(n),调整用时O(logn)，时间复杂度O(nlogn)
     * 不稳定：若父节点=右子节点<左子节点，调整后相同元素的相对为位置改变
     *
     */

    /*****************************************************************************************
     * 冒泡排序
     *
     * 1.
     */
    public static void bubbleSort(int[] arr) {
        /** bei*/
//        int len=arr.length;
//        for(;len>0;len--){
//            for(int i=0;i<len;i++){
//                if(arr[i]>arr[i+1]){
//                    int temp=arr[i];
//                    arr[i]=arr[i+1];
//                    arr[i+1]=arr[i];
//                }
//            }
//        }
        /** iTimeTraveler*/
        for (int i = arr.length; i > 0; i--) {
            for (int j = 0; j < i && (j + 1) < i; j++) {
                if (arr[j] > arr[j + 1]) {
                    int temp = arr[j];
                    arr[j] = arr[j + 1];
                    arr[j + 1] = temp;
                    System_out_println("Sorting: " + Arrays.toString((arr)));
                }
            }
        }
    }
    /** 评价：
     * 时间内复杂度O(n^2)
     * 稳定: 只有在相邻元素大小不符合要求时才调换他们的位置
     *      不改变相同元素间相对顺序
     */

    /*****************************************************************************************
     * 快速排序(递归)
     *
     * 对冒泡排序的一种改进，借用了分治的思想。
     * 1.从数列中挑出一个元素，称为基准（pivot）
     * 2.重新排序数列，所有比基准值小的元素摆放基准前面，所有比基准值大的元素摆在后面
     * 3.递归地（resursively）把小于基准值元素的子数列和大于基准值元素的子数列排序
     * @param arr 待排序数组
     * @param low 左边界
     * @parar high 右边界
     *
     */

    public static void quickSort(int[] arr, int low, int high) {
        /** bei*/
//        int len=arr.length;
//        int pivot=len/2;
//        int low=0;
//        int high=len-1;
//        for(;low<pivot;low++){
//            if(arr[low]>arr[pivot]){
//                int temp=arr[low];
//                arr[low]=arr[high];
//                arr[high]=temp;
//                for(;high>pivot;high--){
//                    if (arr[high] < arr[pivot]) {
//
//                    }
//                }
//            }
//        }
        /** iTimeTraveler*/
        //思想：挖坑填数 + 分治法
        if (arr.length < 0) return;
        if (low >= high) return;
        int left = low;
        int right = high;

        int temp = arr[left];//挖坑1：保存枢轴值
        while (left < right) {
            while (left < right && arr[right] >= temp) {//坑2：从后向前找到比枢轴值小的元素，出入到枢轴位置坑1中
                right--;
            }
            arr[left] = arr[right];
            while (left < right && arr[left] <= temp) {//坑3：从前往后找比枢轴值大的元素，放到坑2中
                left++;
            }
            arr[right] = arr[left];
        }
        arr[left] = temp;//枢轴值归位于最终正确位置
        quickSort(arr, low, left - 1);
        quickSort(arr, left + 1, high);
    }
    /**
     * 评价：平均时间复杂度为O(nlogn)在同数量级下平均性能最好
     *     平均情况下来看，甚至优于同O(nlogn)复杂度的归并排序
     * 不稳定：{3，2，2} --->{2,2,3}
     */

    /**
     * 快速排序（非递归）
     * <p>
     * 1.从数列中跳出一个元素作为pivot
     * 2.重新排列序列，所有比基准值小的元素摆前面，大的摆后面
     * 3.把分区后的两个区间边界（low和high）压入栈保存
     */
    public static void quickSortByStack(int[] arr) {
        if (arr.length <= 0) return;
        Stack<Integer> stack = new Stack<Integer>();

        //初始状态的左右指针入栈（low和high指针）
        stack.push(0);
        stack.push(arr.length - 1);
        while (!stack.isEmpty()) {
            int high = stack.pop();//出栈进行分区操作
            int low = stack.pop();

            int pivotIdx = partition(arr, low, high);

            //划分分区后，分区的左右指针入栈
            if (pivotIdx > low) {
                stack.push(pivotIdx);
                stack.push(pivotIdx - 1);
            }
            if (pivotIdx < high && pivotIdx >= 0) {
                stack.push(pivotIdx + 1);
                stack.push(high);
            }
        }
    }

    private static int partition(int[] arr, int low, int high) {
        //再分区内完成枢轴值归位的工作
        if (arr.length <= 0) return -1;
        if (low >= high) return -1;
        int left = low;
        int right = high;

        int pivot = arr[left];
        while (left < right) {
            while (left < right && arr[right] >= pivot) {
                right--;
            }
            arr[left] = arr[right];
            while (left < right && arr[right] <= pivot) {
                right++;
            }
            arr[left] = arr[right];
        }
        arr[left] = arr[left];

        return left;//返回变量left
    }

    /**
     * 归并排序
     * 采用分治思想。将若干有序子列合并成有序整列
     * 主要操作：分解 + 合并
     */
    public static int[] mergingSort(int[] arr) {
        /**
         * 递归实现
         *
         * 1.将序列每相邻两个数字进行归并操作，形成floor(n/2)个子序列
         * 2.将上述序列再次归并，形成floor(n/4)个子序列，每个子序列包含四个元素
         * 3.重复步骤2
         */
        /** bei*/
//        int len=arr.length;
//        int mid=len/2;
//        for(int i=0;i<len;i++){
//            for(int j=;j<=len/){
//
//            }
//        }
        if (arr.length <= 1) return arr;

        int num = arr.length >> 1;
        int[] leftArr = Arrays.copyOfRange(arr, 0, num);
        int[] rightArr=Arrays.copyOfRange(arr,num,arr.length);
        System_out_println("split two arrry"+Arrays.toString(leftArr)+"And"+Arrays.toString(rightArr));
        return mergeTwoArray(mergingSort(leftArr),mergingSort(rightArr));//不断拆分为最小单元，再排序合并
    }

    private static int[] mergeTwoArray(int[] arr1,int[] arr2){
        int i=0,j=0,k=0;
        int[] result=new int[arr1.length+arr2.length];
        while(i<arr1.length&&j<arr2.length){
            if(arr1[i]<=arr2[j]){
                result[k++]=arr1[i++];
            }else{
                result[k++]=arr2[j++];
            }
        }
        while(i<arr1.length){
            result[k++]=arr1[i++];
        }
        while(j<arr1.length){
            result[k++]=arr1[j++];
        }
        System_out_println("Merging: "+Arrays.toString(result));

        return result;
    }

    /**
     * 基数排序（LSD从最低位开始）
     *
     * 基数排序适用于：
     *      （1）数据范围小于1000；
     *      （2）每个数值都要大于等于0；
     *
     * 步骤：1.取得数组中的最大数，并取得位数
     *      2.arr为原始数组，从最低位开始取每位组成radix数组
     *      3.对radix进行计数排序（利用计数排序适用于小范围数的特点）
     * @param arr 待排序数组
     */
    public static void radixSort(int[] arr) {
        //取得数组中的最大数，并取得位数
        int max=0;
        for(int i=0;i<arr.length;i++){
            if(max<arr[i]){
                max=arr[i];
            }
        }
        int maxDigit=1;
        while(max/10>0){
            maxDigit++;
            max=max/10;
        }
        System_out_println("maxDigit: "+maxDigit);

//        申请一个桶空间
        int[][] buckets=new int[10][arr.length];
        int base =10;
//        从低位到高位，对每一位遍历，将所有元素分配到桶中
        for(int i=0;i<maxDigit;i++){
            int[] bktLen=new int[10];//存储各个桶中存储元素的数量

            //将所有元素分配到桶中
            for(int j=0;j<arr.length;j++){
                int whichBucket=(arr[j]%base)/(base/10);//此句存疑，感觉分母部分完全无用
                buckets[whichBucket][bktLen[whichBucket]++]=arr[j];
            }

            //收集：将不同桶里数据挨个捞出来，为下一轮高位排序做准备，由于靠近桶底的元素排名靠前，因此从桶底开始捞
            int k=0;
            for(int b=0;b<buckets.length;b++){
                for(int p=0;p<buckets[b];p++){
                    arr[k++]=buckets[b][p];
                }
            }


        }
    }

}
