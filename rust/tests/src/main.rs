fn main() {
    let s1 = String::from("Hello world"); 

    let s2 = takes_ownership(s1); 
    println!("{}", s1); 
    println!("{}", s2); 
}
fn takes_ownership(s: String) -> String {
  s
}
