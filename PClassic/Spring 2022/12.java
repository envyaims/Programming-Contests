// curteosy to frank

import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;
import java.io.*;

public class terrifyingTetra {
    public static double[] getMedianOnLine(double[] pointA, double[] pointB){
      double[] output = new double[3];
      for(int i = 0; i < 3; i++){
        output[i] = (pointA[i] + pointB[i]) / 2;
      }
      return output;
    }
    public static double[] vectorSubtraction(double[] pointA, double[] pointB){
      double[] output = new double[3];
      for(int i = 0; i < 3; i++){
        output[i] = pointA[i] - pointB[i];
      }
      return output;
    }
    public static double dotProduct(double[] vectorA, double[] vectorB){
      double output = 0;
      for(int i = 0; i < 3; i++){
        output += (vectorA[i] * vectorB[i]);
      }
      return output;
    }
    public static void multiplyVectorByScalar(double[] vector, double scalar){
      for(int i = 0; i < vector.length; i++){
        vector[i] *= scalar;
      }
    }
    public static double[] terrifyingTetra(double[][] ps) {
      /*
      Algorithm:
      Find 3 planes perpendicular to the sides and equations for them in form ax + by + cz = d
      Solve for the solution somehow
      */
      //System.out.println("tetra called");
      double[] arbPointD = ps[3];
      double[][] planeEquations = new double[3][];
      final int[][] hardcodedOppositeList = {{1, 2}, {0, 2}, {0, 1}};
      for(int i = 0; i <= 2; i++){
        double[] median = getMedianOnLine(ps[hardcodedOppositeList[i][0]], ps[hardcodedOppositeList[i][1]]);
        double[] vectorPerpendicular = vectorSubtraction(ps[i], arbPointD);
        //System.out.println(Arrays.toString(median));
        //System.out.println(Arrays.toString(vectorPerpendicular));
        /*
          for plane ax + by + cz = d, <x, y, z> * vectorPerpendicular = 0,
          ie. <a, b, c> = vectorPerpendicular
          d = vectorPerpendicular * median
        */
        double[] planeEquation = new double[4];
        for(int j = 0; j <= 2; j++){
          planeEquation[j] = vectorPerpendicular[j];
        }
        planeEquation[3] = dotProduct(vectorPerpendicular, median);
        planeEquations[i] = planeEquation;
        //System.out.println(Arrays.toString(planeEquation));
      }
      //System.out.println(Arrays.deepToString(planeEquations));
      //planeEquations = new double[][]{{6.42,20, 20.69, 0.71}, {4, 5.1, 8, 9}, {6, 7, 10, 11.23}};
      // Step 1: Eliminate x terms
      ArrayList<Integer> zerolocs = new ArrayList<Integer>();
      for(int i = 0; i <= 2; i++){
        if(planeEquations[i][0] == 0){
          zerolocs.add(i);
        }
      }
      double[][] planeEquationsTwo = new double[2][3];
      if(zerolocs.size() == 0){
        for(int i = 0; i <= 2; i++){
          multiplyVectorByScalar(planeEquations[i], (1/planeEquations[i][0]));
        }
        for(int i = 0; i <= 2; i++){
          planeEquationsTwo[0][i] = (planeEquations[0][i+1] - planeEquations[1][i+1]);
          planeEquationsTwo[1][i] = (planeEquations[0][i+1] - planeEquations[2][i+1]);
        }
        //System.out.println("case 0");
      } else if (zerolocs.size() == 1){
        int zeroloc = zerolocs.get(0);
        for(int i = 0; i <= 2; i++){
          planeEquationsTwo[0][i] = planeEquations[zeroloc][i+1];
        }
        ArrayList<Integer> toSubtract = new ArrayList<Integer>();
        for(int i = 0; i <= 2; i++){
          if(i == zeroloc){
            continue;
          }
          // normalise vector
          toSubtract.add(i);
          multiplyVectorByScalar(planeEquations[i], (1/planeEquations[i][0]));
        }
        for(int i = 0; i <= 2; i++){
          int indexOne = toSubtract.get(0);
          int indexTwo = toSubtract.get(1);
          planeEquationsTwo[1][i] = (planeEquations[indexOne][i+1] - planeEquations[indexTwo][i+1]);
        }
        //System.out.println("case 1");
      } else { // 3 should not happen otherwise the equations are not linearly independent and bad things happen
        for(int i = 0; i <= 1; i++){
          int equationIndex = zerolocs.get(i);
          for(int j = 0; j <= 2; j++){
            planeEquationsTwo[i][j] = planeEquations[equationIndex][j+1];
          }
        }
        //System.out.println("case 2");
      }
      double[] solution = new double[3];
      // Step 2: 2 equations of 2 unknowns, now solve ay + bz = c, dy + ez = f
      //planeEquationsTwo = new double[][] {{6.3, 2.1, 9}, {0, 8.4, -1.75}};
      if(planeEquationsTwo[0][0] == 0){
        solution[2] = (planeEquationsTwo[0][2] / planeEquationsTwo[0][1]);
        solution[1] = ((planeEquationsTwo[1][2] - (planeEquationsTwo[1][1] * solution[2])) / (planeEquationsTwo[1][0])); // dy + ez = f, y = (f - ez) / d
        //System.out.println("case 2.1");
      } else if (planeEquationsTwo[1][0] == 0){ // 0y + ez = f, z = (f/e)
        solution[2] = (planeEquationsTwo[1][2] / planeEquationsTwo[1][1]);
        solution[1] = ((planeEquationsTwo[0][2] - (planeEquationsTwo[0][1] * solution[2])) / (planeEquationsTwo[0][0])); // ay + bz = c, y = (c - bz) / a
        //System.out.println("case 2.2");
      } else {
        for(int i = 0; i < 2; i++){
          multiplyVectorByScalar(planeEquationsTwo[i], (1/planeEquationsTwo[i][0])); // normalise vectors based on y
        }
        double diffz = planeEquationsTwo[0][1] - planeEquationsTwo[1][1];
        double diffd = planeEquationsTwo[0][2] - planeEquationsTwo[1][2];
        // diffz * z = diffd
        solution[2] = diffd / diffz;
        solution[1] = ((planeEquationsTwo[0][2] - (planeEquationsTwo[0][1] * solution[2])) / planeEquationsTwo[0][0]);
        //System.out.println("case 2.3");
      }
      // Step 3: Plug in y, z into an equation with non-zero x to get x
      for(int i = 0; i < 2; i++){
        if(planeEquations[i][0] == 0){
          continue;
        }
        // ax + by + cz = d, x = (d - cz - by) / a
        solution[0] = ((planeEquations[i][3] - planeEquations[i][2] * solution[2] - planeEquations[i][1] * solution[1]) / planeEquations[i][0]);
        break;
      }
      //System.out.println(Arrays.toString(solution));
      return solution;
    }

    public static void main(String[] args) throws Exception {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.valueOf(reader.readLine());
        for (int i = 0; i < t; i++) {
            double[][] points = new double[4][3];
            for (int j = 0; j < 4; j++) {
                String point = reader.readLine();
                String[] split = point.split(" ");
                for (int a = 0; a < 3; a++) {
                    points[j][a] = Double.valueOf(split[a]);
                }
            }
            double[] output = terrifyingTetra(points);
            for (int j = 0; j < output.length; j++) {
                System.out.print((Math.round(output[j] * 10.0) / 10.0) + " ");
            }
            System.out.println();
        }
    }
}
