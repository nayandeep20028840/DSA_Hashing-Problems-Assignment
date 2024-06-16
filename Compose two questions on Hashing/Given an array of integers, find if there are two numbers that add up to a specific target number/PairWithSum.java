import java.util.HashMap;

public class PairWithSum {
    public static boolean hasPairWithSum(int[] arr, int target) {
        HashMap<Integer, Integer> seen = new HashMap<>();
        for (int num : arr) {
            if (seen.containsKey(target - num)) {
                return true;
            }
            seen.put(num, num); // Store the number as both key and value
        }
        return false;
    }

    public static void main(String[] args) {
        int[] arr = {1, 4, 45, 6, 10, 8};
        int target = 16;

        if (hasPairWithSum(arr, target)) {
            System.out.println("Array has two elements with sum " + target);
        } 
        else {
            System.out.println("Array doesn't have two elements with sum " + target);
        }
    }
}
