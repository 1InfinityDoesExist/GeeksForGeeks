package com.example.demo;

import java.util.Arrays;

public class DemoApplication {
	
	
	public String reverseT(String str) {
		char[] content = str.toCharArray();
		Arrays.sort(content);
		System.out.println(new String(content));
		System.out.println(String.valueOf(content));
		
		return null;
	}

	public static void main(String[] args) {
		String str = "aabbccaa";
		DemoApplication demoApplication = new DemoApplication();
		System.out.println(demoApplication.reverseT(str));
		
	}

}

