package model;

import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.util.Properties;

import entities.User;

public class UserModel {
	/**
	 * ����һ����Ϊ���û���.properties���ļ������û�ע����Ϣд�뵽���ļ��С�
	 * @param userFile  ���û����������ļ�����
	 * @param user �����û���Ϣ��ʵ�������
	 * @return ����ļ��Ѵ��ڣ���ʾ���û����ѱ�ע�ᣬ����false����֮����ɴ����ļ���д�����ݵĲ���������true
	 * @throws IOException
	 */
	public boolean registerUser(File userFile,User user) throws IOException{
		if (userFile.exists()) {
			return false;
		}else{
			userFile.createNewFile();
			Properties properties = new Properties();
			OutputStream outputStream = new FileOutputStream(userFile);
			properties.setProperty("userName", user.getUserName());
			properties.setProperty("pwd",user.getPwd());
			properties.setProperty("gender",user.getGender());
			properties.setProperty("category",user.getCategory());
			properties.setProperty("interest", user.getInterest());
			properties.setProperty("photo", user.getPhoto());
			properties.store(outputStream, "suowang@cuit.edu.cn");
			outputStream.close();
			return true;
		}
	}
	public boolean registerUser(User user) throws IOException{
		File dir = new File("d:\\users");
		if (!dir.exists()) {
			dir.mkdirs();
		}
		File userFile = new File(dir.getAbsolutePath() + "/" + user.getUserName() + ".properties");
		userFile.createNewFile();
		Properties properties = new Properties();
		OutputStream outputStream = new FileOutputStream(userFile);
		properties.setProperty("userName", user.getUserName());
		properties.setProperty("pwd", user.getPwd());
		properties.setProperty("gender", user.getGender());
		properties.setProperty("category", user.getCategory());
		properties.setProperty("interest", user.getInterest());
		properties.setProperty("photo", user.getPhoto());
		properties.store(outputStream, "suowang@cuit.edu.cn");
		outputStream.close();
		return true;
	}
	/**
	 * ���û�ע���ļ�����֤�û��ĵ�¼���������Ƿ�ƥ��
	 * @param userFile �û�ע���ļ�
	 * @param pwd �û���¼ʱ�ύ������
	 * @return ���δ�ҵ���¼�ļ� ��ʾ���û���δע�ᣬ����false������û��������벻ƥ�䷵��false����֮����true
	 * @throws IOException
	 */
	public boolean loginCheck(File userFile,String pwd) throws IOException{
		if (userFile.exists()) {
			Properties properties = new Properties();
			FileInputStream fis = new FileInputStream(userFile);
			properties.load(fis);
			if (properties.getProperty("pwd").equals(pwd)) {
				return true;
			}else{
				return false;
			}
			
		}else{
			return false;
		}
	}
	
	public User findUser(File userFile) {
		if(userFile.exists()) {
			Properties properties = new Properties();
			User user = new User();
			try {
				FileInputStream inputStream = new FileInputStream(userFile);
				properties.load(inputStream);
				user.setUserName(properties.getProperty("userName"));
				user.setPwd(properties.getProperty("pwd"));
				user.setGender(properties.getProperty("gender"));
				user.setCategory(properties.getProperty("category"));
				// 去掉括号
				String interest = properties.getProperty("interest");
				user.setInterest(interest.substring(1, interest.length()-1));
				user.setPhoto(properties.getProperty("photo"));
				return user;
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
				return null;
			}
			
		} else {
			return null;
		}
	}
	
	public static void main(String[] args) throws IOException {
		User user = new User();
		user.setCategory("student");
		user.setGender("male");
		user.setInterest("football");
		user.setPwd("123");
		user.setUserName("tomcat");
		user.setPhoto("afsd");
		UserModel userModel = new UserModel();
		userModel.registerUser(user);
	}
}
