package com.revature.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.springframework.beans.factory.annotation.Autowired;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;

import com.revature.domain.DragonCharacter;
import com.revature.service.AppService;

@Controller
public class LoginCtrl {

	@Autowired
	private AppService service;

	@RequestMapping("/login")
	public String login1() {
		return "/static/features/form/login.html";
	}

	@RequestMapping("/home")
	public String home() {
		return "/static/home.html";
	}

	@RequestMapping("/")
	public String index() {
		return "/static/index.html";
	}
	
	@RequestMapping("/welcome")
	public String welcome() {
		return "/static/index.html";
	}

	@RequestMapping(value = "/login", method = RequestMethod.POST)
	public String login2(DragonCharacter user, HttpServletRequest request) {

		user.setUserId(1);
		DragonCharacter clientUser = service.getCharacter(user);

		if (clientUser != null) {
			// store the valid user into the session
			HttpSession session = request.getSession(); // create one or get existing
			session.setAttribute("user", clientUser);

			return "redirect: home";

		} else {
			return "redirect: login";
		}
	}
}
