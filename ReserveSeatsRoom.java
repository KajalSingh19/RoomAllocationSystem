
import java.util.Scanner;

class RoomAllocation {
    String roomNo;
        private String host;
        private String startTime;
        private String endTime;
        //private String from;
       // private String to;
        private String[][][] chairs = new String[8][4][10];
    
        public RoomAllocation() {
            empty();
        }
    
        public void reserveRoom() {
            Scanner sc = new Scanner(System.in);
    
            System.out.print("Book a Room by entering its Room number: ");
            roomNo = sc.nextLine();
    
            System.out.print("Room is Booked by (Host's Name): ");
            host = sc.nextLine();
    
            System.out.print("Check-in Time(am/pm): ");
            startTime = sc.nextLine();
    
            System.out.print("Check-out Time(am/pm): ");
            endTime = sc.nextLine();
    
          //  System.out.print("From: ");
            //from = sc.nextLine();
    
            //System.out.print("To: ");
            //to = sc.nextLine();
        }
    
        public void allotment() {
            Scanner sc = new Scanner(System.in);
            System.out.print("Room number: ");
            String num = sc.nextLine();
    
            if (!roomNo.equals(num)) {
                System.out.println("Room number not found!");
                return;
            }
    
            System.out.print("Chair number (1-32): ");
            int chair = sc.nextInt();
            sc.nextLine(); // Consume newline
    
            if (chair < 1 || chair > 32) {
                System.out.println("There are only 32 chairs available in the room.");
                return;
            }
    
            int row = (chair - 1) / 4;
            int col = (chair - 1) % 4;
    
            if (chairs[row][col][0].equals("Empty")) {
                System.out.print("Seat is reserved for (name): ");
                chairs[row][col][0] = sc.nextLine();
                System.out.println("Your seat is reserved.");
            } else {
                System.out.println("The chair number is already reserved.");
            }
        }
    
        public void empty() {
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    chairs[i][j][0] = "Empty";
                }
            }
        }
    
        public void show() {
            System.out.println("Room Number: " + roomNo);
            System.out.println("Host: " + host);
            System.out.println("Start Time: " + startTime);
            System.out.println("End Time: " + endTime);
         //   System.out.println("From: " + from);
           // System.out.println("To: " + to);
    
            for (int i = 0; i < 8; i++) {
                for (int j = 0; j < 4; j++) {
                    System.out.print((i * 4 + j + 1) + ". " + chairs[i][j][0] + "\t");
                }
                System.out.println();
            }
        }
    }
    public class  ReserveSeatsRoom{
        
    
        public static void main(String[] args) {
            Scanner sc = new Scanner(System.in);
            RoomAllocation[] rooms = new RoomAllocation[10];
            int roomCount = 0;
    
            while (true) {
                System.out.println("\n1. Book a Room");
                System.out.println("2. Make Reservation for a Chair");
                System.out.println("3. Check Status for a Room");
                System.out.println("4. Exit");
                System.out.print("Enter Your Choice: ");
                int choice = sc.nextInt();
                sc.nextLine(); // Consume newline
    
                switch (choice) {
                    case 1:
                        if (roomCount < 10) {
                            rooms[roomCount] = new RoomAllocation();
                            rooms[roomCount].reserveRoom();
                            roomCount++;
                        } else {
                            System.out.println("Maximum room limit reached!");
                        }
                        break;
                    case 2:
                        System.out.print("Enter Room number for reservation: ");
                        String roomNo = sc.nextLine();
                        boolean found = false;
                        for (RoomAllocation room : rooms) {
                            if (room != null && roomNo.equals(room.roomNo)) {
                                room.allotment();
                                found = true;
                                break;
                            }
                        }
                        if (!found) {
                            System.out.println("Room not found!");
                        }
                        break;
                    case 3:
                        System.out.print("Enter Room number to check status: ");
                        roomNo = sc.nextLine();
                        found = false;
                        for (RoomAllocation room : rooms) {
                            if (room != null && roomNo.equals(room.roomNo)) {
                            room.show();
                            found = true;
                            break;
                        }
                    }
                    if (!found) {
                        System.out.println("Room not found!");
                    }
                    break;
                case 4:
                    System.out.println("Thank you!");
                    return;
                default:
                    System.out.println("Invalid choice!");
            }
      sc.close();  }
        
    }
}
