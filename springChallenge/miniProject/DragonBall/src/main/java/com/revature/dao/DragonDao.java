package com.revature.dao;

import com.revature.domain.DragonCharacter;
import com.revature.domain.Finisher;

public interface DragonDao {

	// Create
	public void createCharacter(DragonCharacter ch);

	public void addFinisher(Finisher f);

	// Read
	public DragonCharacter getCharacter(DragonCharacter ch);

	public Finisher getFinisher(Finisher f);

	// Update
	public void updateCharacter(DragonCharacter ch);

	public void updateFinisher(Finisher f);

	// Delete
	public void deleteCharacter(DragonCharacter ch);

	public void deleteFinisher(Finisher f);

}
