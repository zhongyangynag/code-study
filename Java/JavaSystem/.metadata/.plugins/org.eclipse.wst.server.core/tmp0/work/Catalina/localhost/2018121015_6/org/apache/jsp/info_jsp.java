/*
 * Generated by the Jasper component of Apache Tomcat
 * Version: Apache Tomcat/9.0.33
 * Generated at: 2020-04-14 10:10:06 UTC
 * Note: The last modified time of this file was set to
 *       the last modified time of the source file after
 *       generation to assist with modification tracking.
 */
package org.apache.jsp;

import javax.servlet.*;
import javax.servlet.http.*;
import javax.servlet.jsp.*;

public final class info_jsp extends org.apache.jasper.runtime.HttpJspBase
    implements org.apache.jasper.runtime.JspSourceDependent,
                 org.apache.jasper.runtime.JspSourceImports {

  private static final javax.servlet.jsp.JspFactory _jspxFactory =
          javax.servlet.jsp.JspFactory.getDefaultFactory();

  private static java.util.Map<java.lang.String,java.lang.Long> _jspx_dependants;

  static {
    _jspx_dependants = new java.util.HashMap<java.lang.String,java.lang.Long>(2);
    _jspx_dependants.put("/WEB-INF/lib/taglibs-standard-impl-1.2.5.jar", Long.valueOf(1586433203773L));
    _jspx_dependants.put("jar:file:/D:/编程/Java/Java/JavaSystem/.metadata/.plugins/org.eclipse.wst.server.core/tmp0/wtpwebapps/2018121015_6/WEB-INF/lib/taglibs-standard-impl-1.2.5.jar!/META-INF/c.tld", Long.valueOf(1425949870000L));
  }

  private static final java.util.Set<java.lang.String> _jspx_imports_packages;

  private static final java.util.Set<java.lang.String> _jspx_imports_classes;

  static {
    _jspx_imports_packages = new java.util.HashSet<>();
    _jspx_imports_packages.add("javax.servlet");
    _jspx_imports_packages.add("javax.servlet.http");
    _jspx_imports_packages.add("javax.servlet.jsp");
    _jspx_imports_classes = null;
  }

  private volatile javax.el.ExpressionFactory _el_expressionfactory;
  private volatile org.apache.tomcat.InstanceManager _jsp_instancemanager;

  public java.util.Map<java.lang.String,java.lang.Long> getDependants() {
    return _jspx_dependants;
  }

  public java.util.Set<java.lang.String> getPackageImports() {
    return _jspx_imports_packages;
  }

  public java.util.Set<java.lang.String> getClassImports() {
    return _jspx_imports_classes;
  }

  public javax.el.ExpressionFactory _jsp_getExpressionFactory() {
    if (_el_expressionfactory == null) {
      synchronized (this) {
        if (_el_expressionfactory == null) {
          _el_expressionfactory = _jspxFactory.getJspApplicationContext(getServletConfig().getServletContext()).getExpressionFactory();
        }
      }
    }
    return _el_expressionfactory;
  }

  public org.apache.tomcat.InstanceManager _jsp_getInstanceManager() {
    if (_jsp_instancemanager == null) {
      synchronized (this) {
        if (_jsp_instancemanager == null) {
          _jsp_instancemanager = org.apache.jasper.runtime.InstanceManagerFactory.getInstanceManager(getServletConfig());
        }
      }
    }
    return _jsp_instancemanager;
  }

  public void _jspInit() {
  }

  public void _jspDestroy() {
  }

  public void _jspService(final javax.servlet.http.HttpServletRequest request, final javax.servlet.http.HttpServletResponse response)
      throws java.io.IOException, javax.servlet.ServletException {

    if (!javax.servlet.DispatcherType.ERROR.equals(request.getDispatcherType())) {
      final java.lang.String _jspx_method = request.getMethod();
      if ("OPTIONS".equals(_jspx_method)) {
        response.setHeader("Allow","GET, HEAD, POST, OPTIONS");
        return;
      }
      if (!"GET".equals(_jspx_method) && !"POST".equals(_jspx_method) && !"HEAD".equals(_jspx_method)) {
        response.setHeader("Allow","GET, HEAD, POST, OPTIONS");
        response.sendError(HttpServletResponse.SC_METHOD_NOT_ALLOWED, "JSP 只允许 GET、POST 或 HEAD。Jasper 还允许 OPTIONS");
        return;
      }
    }

    final javax.servlet.jsp.PageContext pageContext;
    javax.servlet.http.HttpSession session = null;
    final javax.servlet.ServletContext application;
    final javax.servlet.ServletConfig config;
    javax.servlet.jsp.JspWriter out = null;
    final java.lang.Object page = this;
    javax.servlet.jsp.JspWriter _jspx_out = null;
    javax.servlet.jsp.PageContext _jspx_page_context = null;


    try {
      response.setContentType("text/html; charset=UTF-8");
      pageContext = _jspxFactory.getPageContext(this, request, response,
      			null, true, 8192, true);
      _jspx_page_context = pageContext;
      application = pageContext.getServletContext();
      config = pageContext.getServletConfig();
      session = pageContext.getSession();
      out = pageContext.getOut();
      _jspx_out = out;

      out.write("\r\n");
      out.write("\r\n");
      out.write("<!DOCTYPE html>\r\n");
      out.write("<html lang=\"en\">\r\n");
      out.write("\t<head>\r\n");
      out.write("\t\t<meta http-equiv=\"content-type\" content=\"text/html; charset=UTF-8\">\r\n");
      out.write("\t\t<meta charset=\"utf-8\">\r\n");
      out.write("\t\t<title>HTML</title>\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t<meta name=\"viewport\" content=\"width=device-width, initial-scale=1, maximum-scale=1\">\r\n");
      out.write("\t\t<link href=\"css/bootstrap.min.css\" rel=\"stylesheet\">\r\n");
      out.write("\t\t\r\n");
      out.write("\t\t<!--[if lt IE 9]>\r\n");
      out.write("\t\t\t<script src=\"//html5shim.googlecode.com/svn/trunk/html5.js\"></script>\r\n");
      out.write("\t\t<![endif]-->\r\n");
      out.write("\t\t<link href=\"css/main1.css\" rel=\"stylesheet\">\r\n");
      out.write("\t</head>\r\n");
      out.write("\t<body>\r\n");
      out.write("<!-- Wrap all page content here -->\r\n");
      out.write("<div id=\"wrap\">\r\n");
      out.write("  \r\n");
      out.write("  <!-- Fixed navbar -->\r\n");
      out.write("  <!-- 导航栏 开始-->\r\n");
      out.write("  <div class=\"navbar navbar-default navbar-fixed-top\">\r\n");
      out.write("    <div class=\"container\">\r\n");
      out.write("      <div class=\"navbar-header\">\r\n");
      out.write("        <button type=\"button\" class=\"navbar-toggle\" data-toggle=\"collapse\" data-target=\".navbar-collapse\">\r\n");
      out.write("          <span class=\"icon-bar\"></span>\r\n");
      out.write("          <span class=\"icon-bar\"></span>\r\n");
      out.write("          <span class=\"icon-bar\"></span>\r\n");
      out.write("        </button>\r\n");
      out.write("        <a class=\"navbar-brand\" href=\"#\">Project</a>\r\n");
      out.write("      </div>\r\n");
      out.write("      <div class=\"collapse navbar-collapse\">\r\n");
      out.write("        <ul class=\"nav navbar-nav\">\r\n");
      out.write("          <li class=\"active\"><a href=\"#\">首页</a></li>\r\n");
      out.write("          <li><a href=\"admin.jsp\">管理页面</a></li>\r\n");
      out.write("          <li><a href=\"#\">导航2</a></li>\r\n");
      out.write("          <li class=\"dropdown\">\r\n");
      out.write("            <a href=\"#\" class=\"dropdown-toggle\" data-toggle=\"dropdown\">菜单 <b class=\"caret\"></b></a>\r\n");
      out.write("            <ul class=\"dropdown-menu\">\r\n");
      out.write("              <li><a href=\"logout.jsp\">退出</a></li>\r\n");
      out.write("            \r\n");
      out.write("              <li class=\"divider\"></li>\r\n");
      out.write("              <li class=\"dropdown-header\">个人信息</li>\r\n");
      out.write("             \r\n");
      out.write("            </ul>\r\n");
      out.write("          </li>\r\n");
      out.write("        </ul>\r\n");
      out.write("      </div><!--/.nav-collapse -->\r\n");
      out.write("    </div>\r\n");
      out.write("  </div>\r\n");
      out.write("   <!-- 导航栏 结束-->\r\n");
      out.write("  <!-- Begin page content -->\r\n");
      out.write("  <div class=\"container\">\r\n");
      out.write("    <div class=\"page-header\">\r\n");
      out.write("      <h1>用户信息：</h1>\r\n");
      out.write("    </div>\r\n");
      out.write("    <p class=\"lead\">用户名：");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${user.userName}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null));
      out.write("</p>\r\n");
      out.write("     <p class=\"lead\">密码：");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${user.pwd}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null));
      out.write("</p>\r\n");
      out.write("      <p class=\"lead\">性别：");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${user.gender}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null));
      out.write("</p>\r\n");
      out.write("       <p class=\"lead\">类型：");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${user.category}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null));
      out.write("</p>\r\n");
      out.write("       <p class=\"lead\">兴趣：");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${user.interest}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null));
      out.write("</p>\r\n");
      out.write("       <p class=\"lead\">注册时间：");
      out.write((java.lang.String) org.apache.jasper.runtime.PageContextImpl.proprietaryEvaluate("${user.regTime}", java.lang.String.class, (javax.servlet.jsp.PageContext)_jspx_page_context, null));
      out.write("</p>\r\n");
      out.write("  </div>\r\n");
      out.write("</div>\r\n");
      out.write("\r\n");
      out.write("<div id=\"footer\">\r\n");
      out.write("  <div class=\"container\">\r\n");
      out.write("    <p class=\"text-muted credit\">网站访问次数：</p>\r\n");
      out.write("  </div>\r\n");
      out.write("</div>\r\n");
      out.write("\r\n");
      out.write("\t<!-- script references -->\r\n");
      out.write("\t\t<script type='text/javascript' src=\"js/jquery-1.9.1.min.js\"></script>\r\n");
      out.write("        <script type='text/javascript' src=\"js/bootstrap.min.js\"></script>\r\n");
      out.write("\t</body>\r\n");
      out.write("</html>");
    } catch (java.lang.Throwable t) {
      if (!(t instanceof javax.servlet.jsp.SkipPageException)){
        out = _jspx_out;
        if (out != null && out.getBufferSize() != 0)
          try {
            if (response.isCommitted()) {
              out.flush();
            } else {
              out.clearBuffer();
            }
          } catch (java.io.IOException e) {}
        if (_jspx_page_context != null) _jspx_page_context.handlePageException(t);
        else throw new ServletException(t);
      }
    } finally {
      _jspxFactory.releasePageContext(_jspx_page_context);
    }
  }
}
