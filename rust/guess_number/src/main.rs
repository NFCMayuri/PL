use std::io; // prelude
fn main() {
    println!("Guess the number");
    println!("Guess a number:");
    let mut guess = String::new();
    // std::io::stdin().read_line(&mut guess).expect("reading error");
    io::stdin().read_line(&mut guess).expect("reading error");
    println!("the number you guess is {}", guess);
}
