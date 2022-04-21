// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "NaveJugador.generated.h"

class UFloatingPawnMovement;

UCLASS()
class DSTARFIGTHERGAME_API ANaveJugador : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ANaveJugador();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/*UPROPERY sirve para especificar como se comporta la propiedad con varios aspectos del motor y editor*/

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UStaticMeshComponent* SM_NaveJugador;

	//UStaticMeshComponent se utiliza para crear una instancia de UStaticMesh. Una Malla estática es una pieza de geometría que consta de un conjunto estático de polígonos

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		UFloatingPawnMovement* FloatingMovement;


public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override; //Abstracto

	virtual void MoveHorizontal(float AxisValue1);

	virtual void MoveVertical(float AxisValue2); 
};