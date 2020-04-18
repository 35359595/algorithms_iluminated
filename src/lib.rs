
pub fn brute_force_search_count_inversions(data: &Vec<u32>) -> usize {
	let mut num_inv = 0;
	for i in 0..data.len() - 1 {
		for j in i..data.len() {
			if data[i] > data[j] {
				num_inv += 1;
			}
		}
	}
	num_inv
}

pub fn recoursive_count_inversions(data: &mut [u32]) -> usize {
	let size = data.len();
	if size <= 2 {
		if size == 1 || data[1] >= data[0] {
			return 0;
		}
		let tmp = data[0];
		data[0] = data[1];
		data[1] = tmp;
		return 1;
	}
	recoursive_count_inversions(&mut data[..size/2]) + 
	recoursive_count_inversions(&mut data[size/2..]) + 
	count_mixed_inversion(&data)
}

fn count_mixed_inversion(data: &[u32]) -> usize {
	let mut accum = 0;
	for i in 0..data.len() - 1 {
		if data[i] > data[i + 1] { accum += 1; }
	}
	accum
}

#[cfg(test)]
mod tests {

	fn get_data() -> Vec<u32> { vec![1,3,5,2,4,6] }

	#[test]
	#[bench]
	fn brute_force_search_count_inversions_test() {
		use super::brute_force_search_count_inversions;
		assert_eq!(3, brute_force_search_count_inversions(&get_data()));
	}

	#[test]
	#[bench]
	fn recoursive_count_inversions_test() {
		use super::recoursive_count_inversions;
		let mut data = get_data();
		assert_eq!(3, recoursive_count_inversions(&mut data[..]));
		for i in 0..data.len() - 1 {
			assert!(data[i] <= data[i + 1]);
		}
	}
}