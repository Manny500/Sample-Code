package com.revature.dao;

import org.hibernate.Session;
import org.hibernate.SessionFactory;
import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Repository;

import com.revature.domain.DragonCharacter;
import com.revature.domain.Finisher;

@Repository
public class DragonDaoImp implements DragonDao {
	
	static{
	       try {
	           Class.forName("oracle.jdbc.driver.OracleDriver");
	       } catch (ClassNotFoundException e) {
	           e.printStackTrace();
	       }
	   }

	@Autowired
	private SessionFactory sessionFactory;

	@Override
	public void createCharacter(DragonCharacter ch) {
		// TODO Auto-generated method stub

	}

	@Override
	public void addFinisher(Finisher f) {
		// TODO Auto-generated method stub

	}

	@Override
	public DragonCharacter getCharacter(DragonCharacter ch) {
		Session session = sessionFactory.getCurrentSession();
		return (DragonCharacter) session.get(DragonCharacter.class, ch.getUserId());
	}

	@Override
	public Finisher getFinisher(Finisher f) {
		// TODO Auto-generated method stub
		return null;
	}

	@Override
	public void updateCharacter(DragonCharacter ch) {
		// TODO Auto-generated method stub

	}

	@Override
	public void updateFinisher(Finisher f) {
		// TODO Auto-generated method stub

	}

	@Override
	public void deleteCharacter(DragonCharacter ch) {
		// TODO Auto-generated method stub

	}

	@Override
	public void deleteFinisher(Finisher f) {
		// TODO Auto-generated method stub

	}

}