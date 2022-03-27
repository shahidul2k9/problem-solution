
import java.util.HashMap;
import java.util.Map;

/**
 * @author Shahidul Islam
 * @date 1/23/2022
 **/

class _133_CloneGraph {
    public Node cloneGraph(Node node) {

        return cloneNode(node, new HashMap<>());
    }
    private Node cloneNode(Node node, Map<Node, Node> nodeMap){
        if (nodeMap.containsKey(node)){
            return nodeMap.get(node);
        }else if (node == null) {
            return null;
        } else {
            Node clonedNode = new Node(node.val);
            nodeMap.put(node, clonedNode );
            for (Node childNode : node.neighbors) {
                clonedNode.neighbors.add(cloneNode(childNode, nodeMap));
            }
            return clonedNode;
        }
    }
}