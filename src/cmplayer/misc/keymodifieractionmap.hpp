#ifndef KEYMODIFIERACTIONMAP_HPP
#define KEYMODIFIERACTIONMAP_HPP

#include "stdafx.hpp"
#include "enums.hpp"

class Record;

struct KeyModifierActionMap {
    struct Action {
        Action(): enabled(false) {}
        Action(bool e, const QString &id): enabled(e), id(id) {}
        bool enabled; QString id;
    };
    KeyModifierActionMap();
    auto operator[](KeyModifier m) -> Action& {return m_map[m];}
    auto operator[](KeyModifier m) const -> const Action {return m_map[m];}
    auto operator[](int id) const -> const Action
        {return m_map[EnumInfo<KeyModifier>::from(id, KeyModifier::None)];}
    auto save(Record &r, const QString &group) const -> void;
    auto load(Record &r, const QString &group) -> void;
private:
    QMap<KeyModifier, Action> m_map;
};

#endif // KEYMODIFIERACTIONMAP_HPP
