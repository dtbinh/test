public class ComputeMortgage {
    public static void main (String[] args) {
        double annualInterestRate;
        int numOfYears;
        double loanAmount;
        System.out.println(
        "Enter yearly interest rate,for example 8.25:"
        );
        annualInterestRate = MyInput.readDouble();
        double monthlyInterestRate = annualInterestRate/1200;
        System.out.println(
        "ENter number of years as an integer, for example 5:");
        numOfYears = MyInput.readInt();

        System.out.println("Enter loan Amount, for exampl 120000.05:");
        loanAmount = MyInput.readDouble();

        double monthlyPayment = loanAmount*monthlyInterestRate/(1-1/(Math.pow(1 + monthlyInterestRate, numOfYears*12)));
        double totalPayment = monthlyPayment*numOfYears*12;

        System.out.println("The monthlyPayment is "+ monthlyPayment);
        System.out.println("The total payment is " + totalPayment);
    }

}
