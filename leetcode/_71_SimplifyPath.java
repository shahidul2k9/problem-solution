
import java.util.Stack;

/**
 * @author Shahidul Islam
 * @date 2/5/2022
 **/
public class _71_SimplifyPath {
    public String simplifyPath(String path) {
        String[] nodeList = path.split("/");
        Stack<String> fileList = new Stack<>();
        for (String file : nodeList) {
            if (!file.isEmpty() && !file.equals(".")) {
                if (file.equals("..")) {
                    if (!fileList.isEmpty())
                        fileList.pop();
                } else {
                    fileList.add(file);
                }
            }
        }
        StringBuffer pathBuilder = new StringBuffer();
        fileList.forEach(file -> pathBuilder.append("/").append(file));
        return pathBuilder.length() == 0 ? "/" : pathBuilder.toString();

    }
}
