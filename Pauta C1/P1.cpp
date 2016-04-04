class Persona{
	string Nombre;
	int edad;
	char sexo;

	Persona *padre;
	Persona *madre;
	Persona *primer_hijo;
	Persona *sgte_hno;
	Persona *pareja;

};
void imprime_mis_primos(Persona *p){
	Persona *aux_tios = p->padre->padre->primer_hijo; 
	//Primer hijo del padre de mi padre, mi tio.
	while(aux_tios && aux_tios != p->padre){
		Persona *aux_primos = aux_tios->primer_hijo;
		while(aux_primos){
			cout<<aux_primos->Nombre<<endl;
			aux_primos = aux_primos->sgte_hno;
		}
		aux_tios = aux_tios->sgte_hno;
	}

	aux_tios = p->madre->padre->primer_hijo;
	while(aux_tios && aux_tios != p->padre){
		Persona *aux_primos = aux_tios->primer_hijo;
		while(aux_primos){
			cout<<aux_primos->Nombre<<endl;
			aux_primos = aux_primos->sgte_hno;
		}
		aux_tios = aux_tios->sgte_hno;
	}
}

int cuenta_mis_sobrinos_de_este_sexo(Persona *p, char s){
	Persona *aux_hermanos = p->padre->primer_hijo;
	int cont = 0;
	while(aux_hermanos && aux_hermanos != p){
		Persona *aux_sobrinos = aux_hermanos->primer_hijo;
		while(aux_sobrinos){
			if(aux_sobrinos->sexo == s){
				cont++;
			}
			aux_sobrinos = aux_sobrinos->sgte_hno;
		}

		aux_hermanos = aux_hermanos->sgte_hno;
	}

	return cont;
}

bool tengo_nietos_mayores_de_edad(Persona *p){
	Persona *hijos = p->primer_hijo;
	if(!hijos) return false;

	while(hijos){
		Persona *nietos = hijos->primer_hijo;
		while(nietos){
			if(nietos->edad >= 18){
				return true;
			}
			nietos->sgte_hno;
		}
		hijos = hijos->sgte_hno;
	}

	return false;
}

int cuenta_mis_descendientes_mayores_de_edad(Persona *p){
	if (cuenta_mis_hijos(p) == 0) return 0;

	Persona *aux = p->primer_hijo;
	int des = 0;
	while(aux){
		if(aux->edad >= 18){
			des++;
		}
		des += cuenta_mis_descendientes_mayores_de_edad(aux);
		aux = aux->sgte_hno;
	}

	return des;

}

int cuenta_mis_hijos(Persona *p){
	Persona *aux = p->primer_hijo;
	int hijos = 0;
	while(aux){
		hijos++;
		aux = aux->sgte_hno;
	}
	return hijos;
}