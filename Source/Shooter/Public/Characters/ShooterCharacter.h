// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ShooterCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;


UCLASS()
class SHOOTER_API AShooterCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AShooterCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;




private:

	/* CameraBoom positions the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;
	
	/* Camera that follows the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/* Base turn rate in degrees/second. Other scaling may affect final turn rate */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseTurnRate;

	/* Base look up/down rate in degrees/second. Other scaling may affect final turn rate */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	float BaseLookUpRate;

public:

	FORCEINLINE USpringArmComponent* GetCameraBoom() const { return CameraBoom; } /* Returns CameraBoom subobject */
	FORCEINLINE UCameraComponent* GetFollowCamera() const { return FollowCamera; } /* Returns FollowCamera subobject */
protected:

	/* Called for forward/Backwards input */
	void MoveForward(float Value);

	/* Called for Right/Left input */
	void MoveRight(float Value);

	/** 
	* Called via input to turn at a given rate.
	* @param Rate This is a normalized rate, i.e 1.0 means 100% of desired turn rate.
	*/
	void TurnAtRate(float Rate);

	/**
	* Called via input to look up/down at a given rate.
	* @param Rate This is a normalized rate, i.e 1.0 means 100% of desired rate.
	*/
	void LookUpAtRate(float Rate);


};