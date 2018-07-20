package com.revature;

import com.revature.domain.DragonCharacter;
import com.revature.service.AppService;

public class Main {
	
	public static void main(String[] args) {
		
		AppService ser = new AppService();
		DragonCharacter goku = new DragonCharacter();
		
		goku.setFirstName("Goku");
		goku.setUserId(1);
		
		System.out.println(ser.getCharacter(goku));
	}
		
}