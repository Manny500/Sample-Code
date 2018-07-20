package com.revature.service;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Service;
import org.springframework.transaction.annotation.Transactional;

import com.revature.dao.DragonDao;
import com.revature.domain.DragonCharacter;

@Service(value = "AppService")
@Transactional
public class AppService {

	@Autowired
	private DragonDao dao;
		
	public DragonCharacter getCharacter(DragonCharacter ch) {
		return dao.getCharacter(ch);
	}
}