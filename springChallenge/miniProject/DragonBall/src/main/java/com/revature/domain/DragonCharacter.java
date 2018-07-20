package com.revature.domain;

import java.io.Serializable;

import javax.persistence.Column;
import javax.persistence.Entity;
import javax.persistence.Id;
import javax.persistence.Table;

@Entity
@Table(name = "CHARACTER")
public class DragonCharacter implements Serializable {

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;

	@Override
	public String toString() {
		return "DragonCharacter [userId=" + userId + ", firstName=" + firstName + ", lastName=" + lastName
				+ ", userName=" + userName + ", password=" + password + ", teamId=" + teamId + "]";
	}

	@Id
	@Column(name = "C_ID")
	private int userId;

	@Column(name = "C_FN")
	private String firstName;

	@Column(name = "C_LS")
	private String lastName;

	@Column(name = "C_USERNAME")
	private String userName;

	@Column(name = "C_PASSWORD")
	private String password;

	@Column(name = "C_TEAM")
	private int teamId;

	public DragonCharacter() {

	}

	public DragonCharacter(int userId, String firstName, String lastName, String userName, String password, int teamId) {
		super();
		this.userId = userId;
		this.firstName = firstName;
		this.lastName = lastName;
		this.userName = userName;
		this.password = password;
		this.teamId = teamId;
	}

	public int getUserId() {
		return userId;
	}

	public void setUserId(int userId) {
		this.userId = userId;
	}

	public String getFirstName() {
		return firstName;
	}

	public void setFirstName(String firstName) {
		this.firstName = firstName;
	}

	public String getLastName() {
		return lastName;
	}

	public void setLastName(String lastName) {
		this.lastName = lastName;
	}

	public String getUserName() {
		return userName;
	}

	public void setUserName(String userName) {
		this.userName = userName;
	}

	public String getPassword() {
		return password;
	}

	public void setPassword(String password) {
		this.password = password;
	}

	public int getTeamId() {
		return teamId;
	}

	public void setTeamId(int teamId) {
		this.teamId = teamId;
	}

	public static long getSerialversionuid() {
		return serialVersionUID;
	}

}