package com.revature.domain;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "FINISHER")
public class Finisher implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Id
	@Column(name = "F_ID")
	private int finishId;

	@Column(name = "F_ATTACK")
	private int attack;
	
	@Column(name = "C_ID")
	private int charId;

	public Finisher() {

	}

	public Finisher(int finishId, int attack, int charId) {
		super();
		this.finishId = finishId;
		this.attack = attack;
		this.charId = charId;
	}

	public int getFinishId() {
		return finishId;
	}

	public void setFinishId(int finishId) {
		this.finishId = finishId;
	}

	public int getAttack() {
		return attack;
	}

	public void setAttack(int attack) {
		this.attack = attack;
	}

	public int getCharId() {
		return charId;
	}

	public void setCharId(int charId) {
		this.charId = charId;
	}

	public static long getSerialversionuid() {
		return serialVersionUID;
	}

	

}
