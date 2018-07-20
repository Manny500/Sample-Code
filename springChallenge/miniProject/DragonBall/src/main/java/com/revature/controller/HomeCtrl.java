package com.revature.controller;

import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpSession;

import org.json.simple.JSONObject;
import org.json.simple.parser.JSONParser;
import org.json.simple.parser.ParseException;
import org.springframework.stereotype.Controller;
import org.springframework.web.bind.annotation.RequestMapping;
import org.springframework.web.bind.annotation.RequestMethod;
import org.springframework.web.bind.annotation.ResponseBody;

import com.google.gson.Gson;
import com.google.gson.GsonBuilder;
import com.revature.domain.DragonCharacter;

@Controller
public class HomeCtrl {

	@RequestMapping(value = { "/profile" }, method = RequestMethod.GET, produces = "application/json")
	@ResponseBody
	public Object profile(HttpServletRequest request) {

		// client wants the bankUser that at this point should be stored in the session
		HttpSession session = request.getSession();

		DragonCharacter clientUser = (DragonCharacter) session.getAttribute("user");

		JSONParser parser = new JSONParser();
		JSONObject json2 = null;

		Gson gson = new GsonBuilder().create();
		String json = gson.toJson(clientUser);

		try {
			json2 = (JSONObject) parser.parse(json);

		} catch (ParseException e) {

			e.printStackTrace();
		}

		return json2;
	}

}
