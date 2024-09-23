var db = require('./../helpers/db_helpers')
var helper = require('./../helpers/helpers')
var multiparty = require("multiparty");
var fs = require('fs');
var imageSavePath = "./public/img/"

const msg_success = "successfully";
const msg_invalidUserPassword = "invalid username and password";
const msg_itemAddedToCart = "Item was successfully added to your cart";
const msg_itemAddToCartFailed = "invalid to add item to your cart";
const msg_orderPlaced = "Your order was successfully done!";
const msg_orderFailed = "invalid to complite your order";
const msg_ordersRetrieved = "Here's your history"
const msg_noOrdersFound = "invalid to find your history"
const msg_cartsRetrieved = "Here's all your carts"
const msg_noCartsFound = "invalid to find your carts"
module.exports.controller = (app, io, socket_list) => {

    app.post('/api/user/login_and_search', (req, res) => {
        helper.Dlog(req.body);
        var reqObj = req.body;
    
        helper.CheckParameterValid(res, reqObj, ["email", "password", "push_token", "item_name"], () => {
    
            getUserWithPasswordData(reqObj.email, reqObj.password, (status, result) => {
                if (status) {
                    var auth_token = helper.createRequestToken();
                    db.query('UPDATE `user_detail` SET `auth_token`= ?,`push_token`=? WHERE `user_id` = ?  AND `status` = ? ', [
                        auth_token, reqObj.push_token, result.user_id, "1"], (err, uResult) => {
                            if (err) {
                                helper.ThrowHtmlError(err, res);
                                return
                            }
    
                            if (uResult.affectedRows > 0) {
                                result.auth_token = auth_token;
                                // После успешного входа в систему выполняем поиск товара
                                searchItem(reqObj.item_name, (searchStatus, searchResult) => {
                                    if (searchStatus) {
                                        res.json({ "status": "1", "payload": {user: result, items: searchResult}, "message": msg_success })
                                    } else {
                                        res.json({ "status": "0", "message": searchResult })
                                    }
                                });
                            } else {
                                res.json({ "status": "0", "message": msg_invalidUserPassword })
                            }
                        })
                } else {
                    res.json({ "status": "0", "message": result })
                }
            })
    
        })
    })

    app.post('/api/user/add_to_cart', (req, res) => {
        helper.Dlog(req.body);
        var reqObj = req.body;
    
        helper.CheckParameterValid(res, reqObj, ["email", "password", "push_token"], () => {
    
            getUserWithPasswordData(reqObj.email, reqObj.password, (status, result) => {
                if (status) {
                    var auth_token = helper.createRequestToken();
                    db.query('UPDATE `user_detail` SET `auth_token`= ?,`push_token`=? WHERE `user_id` = ?  AND `status` = ? ', [
                        auth_token, reqObj.push_token, result.user_id, "1"], (err, uResult) => {
                            if (err) {
                                helper.ThrowHtmlError(err, res);
                                return
                            }
    
                            if (uResult.affectedRows > 0) {
                                result.auth_token = auth_token;
                                // После успешного входа в систему выполняем поиск товара
                                helper.CheckParameterValid(res, reqObj, ["user_id", "restaurant_id", "menu_item_id", "portion_id", "ingredient_id", "qty"], () => {

                                    db.query('INSERT INTO `cart_detail`(`cart_id`, `user_id`, `restaurant_id`, `menu_item_id`, `portion_id`, `ingredient_id`, `qty`, `create_date`, `update_date`, `status`) VALUES (?, ?, ?, ?, ?, ?, ?, NOW(), NOW(), "1")', 
                                    [reqObj.cart_id, reqObj.user_id, reqObj.restaurant_id, reqObj.menu_item_id, reqObj.portion_id, reqObj.ingredient_id, reqObj.qty], 
                                    (err, result) => {
                                        if (err) {
                                            helper.ThrowHtmlError(err, res);
                                            return
                                        }
                            
                                        if (result.affectedRows > 0) {
                                            res.json({ "status": "1", "message": msg_itemAddedToCart })
                                        } else {
                                            res.json({ "status": "0", "message": msg_itemAddToCartFailed })
                                        }
                                    })
                                })
                            } else {
                                res.json({ "status": "0", "message": msg_invalidUserPassword })
                            }
                        })
                } else {
                    res.json({ "status": "0", "message": result })
                }
            })
    
        })
    })

    app.post('/api/user/place_order', (req, res) => {
        helper.Dlog(req.body);
        var reqObj = req.body;
    
        helper.CheckParameterValid(res, reqObj, ["email", "password", "push_token"], () => {
    
            getUserWithPasswordData(reqObj.email, reqObj.password, (status, result) => {
                if (status) {
                    var auth_token = helper.createRequestToken();
                    db.query('UPDATE `user_detail` SET `auth_token`= ?,`push_token`=? WHERE `user_id` = ?  AND `status` = ? ', [
                        auth_token, reqObj.push_token, result.user_id, "1"], (err, uResult) => {
                            if (err) {
                                helper.ThrowHtmlError(err, res);
                                return
                            }
    
                            if (uResult.affectedRows > 0) {
                                result.auth_token = auth_token;
                                // После успешного входа в систему выполняем поиск товара
                                helper.CheckParameterValid(res, reqObj, ["cart_id", "delivery_address", "delivery_lat", "delivery_long", "delivery_note", "sub_total", "delivery_cost", "payable_total", "order_status", "transaction_id", "payment_method", "payment_status"], () => {
    
                                    db.query('INSERT INTO `order_detail`(`order_id`, `cart_id`, `delivery_address`, `delivery_lat`, `delivery_long`, `delivery_note`, `sub_total`, `delivery_cost`, `payable_total`, `order_status`, `transaction_id`, `payment_method`, `payment_status`, `create_date`, `update_date`, `status`) VALUES (?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, ?, NOW(), NOW(), "1")', 
                                    [reqObj.order_id, reqObj.cart_id, reqObj.delivery_address, reqObj.delivery_lat, reqObj.delivery_long, reqObj.delivery_note, reqObj.sub_total, reqObj.delivery_cost, reqObj.payable_total, reqObj.order_status, reqObj.transaction_id, reqObj.payment_method, reqObj.payment_status], 
                                    (err, result) => {
                                        if (err) {
                                            helper.ThrowHtmlError(err, res);
                                            return
                                        }
                            
                                        if (result.affectedRows > 0) {
                                            res.json({ "status": "1", "message": msg_orderPlaced })
                                        } else {
                                            res.json({ "status": "0", "message": msg_orderFailed })
                                        }
                                    })
                                })
                            } 
                            else {
                                res.json({ "status": "0", "message": msg_invalidUserPassword })
                            }
                        })
                } else {
                    res.json({ "status": "0", "message": result })
                }
            })
    
        })
    
        
    })

    app.post('/api/user/history', (req, res) => {
        helper.Dlog(req.body);
        var reqObj = req.body;
    
        helper.CheckParameterValid(res, reqObj, ["email", "password", "push_token"], () => {
    
            getUserWithPasswordData(reqObj.email, reqObj.password, (status, result) => {
                if (status) {
                    var auth_token = helper.createRequestToken();
                    db.query('UPDATE `user_detail` SET `auth_token`= ?,`push_token`=? WHERE `user_id` = ?  AND `status` = ? ', [
                        auth_token, reqObj.push_token, result.user_id, "1"], (err, uResult) => {
                            if (err) {
                                helper.ThrowHtmlError(err, res);
                                return
                            }
    
                            if (uResult.affectedRows > 0) {
                                result.auth_token = auth_token;
                                // После успешного входа в систему выполняем поиск товара
                                helper.CheckParameterValid(res, reqObj, ["name"], () => {

                                    db.query('SELECT o.* FROM `order_detail` o JOIN `cart_detail` c ON o.cart_id = c.cart_id JOIN `user_detail` u ON c.user_id = u.user_id WHERE u.name = ? AND c.status != ?', 
                                    [reqObj.name, "2"], 
                                    (err, result) => {
                                        if (err) {
                                            helper.ThrowHtmlError(err, res);
                                            return
                                        }
                            
                                        if (result.length > 0) {
                                            res.json({ "status": "1", "orders": result, "message": msg_ordersRetrieved })
                                        } else {
                                            res.json({ "status": "0", "message": msg_noOrdersFound })
                                        }
                                    })
                                })
                            } else {
                                res.json({ "status": "0", "message": msg_invalidUserPassword })
                            }
                        })
                } else {
                    res.json({ "status": "0", "message": result })
                }
            })
    
        })
    })

    app.post('/api/user/carts', (req, res) => {
        helper.Dlog(req.body);
        var reqObj = req.body;
    
        helper.CheckParameterValid(res, reqObj, ["email", "password", "push_token"], () => {
    
            getUserWithPasswordData(reqObj.email, reqObj.password, (status, result) => {
                if (status) {
                    var auth_token = helper.createRequestToken();
                    db.query('UPDATE `user_detail` SET `auth_token`= ?,`push_token`=? WHERE `user_id` = ?  AND `status` = ? ', [
                        auth_token, reqObj.push_token, result.user_id, "1"], (err, uResult) => {
                            if (err) {
                                helper.ThrowHtmlError(err, res);
                                return
                            }
    
                            if (uResult.affectedRows > 0) {
                                result.auth_token = auth_token;
                                // После успешного входа в систему выполняем поиск товара
                                helper.CheckParameterValid(res, reqObj, ["name"], () => {

                                    db.query('SELECT c.* FROM `cart_detail` c JOIN `user_detail` u ON c.user_id = u.user_id WHERE u.name = ? AND c.status != ?', 
                                    [reqObj.name, "2"], 
                                    (err, result) => {
                                        if (err) {
                                            helper.ThrowHtmlError(err, res);
                                            return
                                        }
                            
                                        if (result.length > 0) {
                                            res.json({ "status": "1", "carts": result, "message": msg_cartsRetrieved })
                                        } else {
                                            res.json({ "status": "0", "message": msg_noCartsFound })
                                        }
                                    })
                                })
                            } else {
                                res.json({ "status": "0", "message": msg_invalidUserPassword })
                            }
                        })
                } else {
                    res.json({ "status": "0", "message": result })
                }
            })
    
        })
    })

    app.post('/api/user/order_status', (req, res) => {
        helper.Dlog(req.body);
        var reqObj = req.body;
    
        helper.CheckParameterValid(res, reqObj, ["email", "password", "push_token", "order_id"], () => {
    
            getUserWithPasswordData(reqObj.email, reqObj.password, (status, result) => {
                if (status) {
                    var auth_token = helper.createRequestToken();
                    db.query('UPDATE `user_detail` SET `auth_token`= ?,`push_token`=? WHERE `user_id` = ?  AND `status` = ? ', [
                        auth_token, reqObj.push_token, result.user_id, "1"], (err, uResult) => {
                            if (err) {
                                helper.ThrowHtmlError(err, res);
                                return
                            }
    
                            if (uResult.affectedRows > 0) {
                                result.auth_token = auth_token;
                                // После успешного входа в систему выполняем поиск заказа
                                db.query('SELECT o.* FROM `order_detail` o WHERE o.order_id = ? AND `status` = ?', 
                                [reqObj.order_id, "1"], 
                                (err, result) => {
                                    if (err) {
                                        helper.ThrowHtmlError(err, res);
                                        return
                                    }
                        
                                    if (result.length > 0) {
                                        res.json({ "status": "1", "orders": result, "message": msg_ordersRetrieved })
                                    } else {
                                        res.json({ "status": "0", "message": msg_noOrdersFound })
                                    }
                                })
                            } else {
                                res.json({ "status": "0", "message": msg_invalidUserPassword })
                            }
                        })
                } else {
                    res.json({ "status": "0", "message": result })
                }
            })
    
        })
    })
    
    
    

}




function searchItem(itemName, callback) {
    db.query('SELECT * FROM `menu_item_detail` WHERE `name` = ? AND `status` = ?', [itemName, '1'], (err, result) => {
        if (err) {
            helper.ThrowHtmlError(err);
            return callback(false, msg_fail)
        }

        if (result.length > 0) {
            return callback(true, result)
        } else {
            return callback(false, msg_itemNotFound)
        }
    })
}

function getUserWithPasswordData(email, password, callback) {
    db.query('SELECT `user_id`, `name`, `email`, `password`, `mobile`, `address`, `image`, `device_type`, `auth_token`, `user_type`  FROM `user_detail` WHERE `email` = ? AND `password` = ? AND `status` = ?', [email, password, '1'], (err, result) => {
        if (err) {
            helper.ThrowHtmlError(err);
            return callback(false, msg_fail)
        }

        if (result.length > 0) {
            return callback(true, result[0])
        } else {
            return callback(false, msg_invalidUserPassword)
        }
    })
}
