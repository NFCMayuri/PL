fn main() {
    let mut s1 = String::from("hello");
    let s2 = &mut s1;
    borrow_from_string(&mut s1);
}
fn borrow_from_string(s: &mut String) -> u32 {
    0
}
