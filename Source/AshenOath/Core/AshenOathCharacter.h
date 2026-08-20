// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "Logging/LogMacros.h"
#include "AshenCharacterInterface.h"
#include "AbilitySystemInterface.h"
#include "AshenOathCharacter.generated.h"

class USpringArmComponent;
class UCameraComponent;
class UInputAction;
struct FInputActionValue;
class UAshenOath_HealthComponent;
class UAshenOath_HurtboxComponent;
class UAshenOath_EquipmentComponent;
class UAshenOath_InventoryComponent;
class UAshenOath_StatsComponent;

DECLARE_LOG_CATEGORY_EXTERN(LogTemplateCharacter, Log, All);

/**
 *  A simple player-controllable third person character
 *  Implements a controllable orbiting camera
 */
UCLASS(abstract)
class AAshenOathCharacter : public ACharacter, public IAshenCharacterInterface, public IAbilitySystemInterface
{
	GENERATED_BODY()

	/** Camera boom positioning the camera behind the character */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	USpringArmComponent* CameraBoom;

	/** Follow camera */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FollowCamera;

	/** Health management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UAshenOath_HealthComponent* HealthComponent;

	/** Hurtbox receiver component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UAshenOath_HurtboxComponent* HurtboxComponent;

	// Optional gameplay components refactored to specialized child subclasses

	/** Inventory management component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	UAshenOath_InventoryComponent* InventoryComponent;

	/** Localized Floating Damage Text Pool */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenDamageTextPool* DamageTextPool;

	/** Player Interaction Raycaster Component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenInteractionComponent* InteractionComponent;

	/** Ability System Component for GAS integration */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenAbilitySystemComponent* AbilitySystemComponent;

	/** Attribute Set for GAS character attributes */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category="Components", meta = (AllowPrivateAccess = "true"))
	class UAshenAttributeSet* AttributeSet;

protected:

	/** Jump Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* JumpAction;

	/** Move Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MoveAction;

	/** Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* LookAction;

	/** Mouse Look Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* MouseLookAction;

	/** Attack Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* AttackAction;

	/** Dodge Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* DodgeAction;

	/** Sprint Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* SprintAction;

	/** Interact Input Action */
	UPROPERTY(EditAnywhere, Category="Input")
	UInputAction* InteractAction;

	/** Attack Anim Montage */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Combat")
	UAnimMontage* AttackMontage;

public:
	// --- Action Delegates ---
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnDodgeStartedSignature);
	DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSprintStartedSignature);

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Character|Events")
	FOnDodgeStartedSignature OnDodgeStarted;

	UPROPERTY(BlueprintAssignable, Category = "Ashen Oath|Character|Events")
	FOnSprintStartedSignature OnSprintStarted;

	// --- Action States ---
	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath|Character|States")
	bool bIsDodging;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath|Character|States")
	bool bIsSprinting;

public:

	/** Constructor */
	AAshenOathCharacter();	

protected:

	/** Initialize input action bindings */
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;

protected:

	/** Called for movement input */
	void Move(const FInputActionValue& Value);

	/** Called for looking input */
	void Look(const FInputActionValue& Value);

	/** Called for attack input */
	void Attack();

	/** Called for dodge input */
	void Dodge();

	/** Called for interact input */
	void Interact();

	/** Called for sprint input */
	void StartSprint();
	void StopSprint();

public:

	/** Handles move inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoMove(float Right, float Forward);

	/** Handles look inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoLook(float Yaw, float Pitch);

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpStart();

	/** Handles jump pressed inputs from either controls or UI interfaces */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoJumpEnd();

	/** Handles dodge execution hook */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoDodge();

	/** Handles sprint triggers */
	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoSprintStart();

	UFUNCTION(BlueprintCallable, Category="Input")
	virtual void DoSprintEnd();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Sanctuary")
	FVector SpawnPosition;

	/** Returns CameraBoom subobject **/
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return CameraBoom; }

	/** Returns FollowCamera subobject **/
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return FollowCamera; }

	// --- IAbilitySystemInterface Override ---
	virtual class UAbilitySystemComponent* GetAbilitySystemComponent() const override;

	// --- IAshenCharacterInterface Override ---
	virtual UAshenOath_HealthComponent* GetHealthComponent_Implementation() const override;
	virtual UAshenOath_EquipmentComponent* GetEquipmentComponent_Implementation() const override;
	virtual UAshenOath_InventoryComponent* GetInventoryComponent_Implementation() const override;
	virtual UAshenOath_StatsComponent* GetStatsComponent_Implementation() const override;
	virtual UAshenOath_SanityComponent* GetSanityComponent_Implementation() const override;
	virtual UAshenOath_StaminaComponent* GetStaminaComponent_Implementation() const override;
	virtual UAshenOath_ManaComponent* GetManaComponent_Implementation() const override;
	virtual UAshenOath_PoiseComponent* GetPoiseComponent_Implementation() const override;

	/** Virtual input buffer getter to avoid FindComponentByClass lookups */
	virtual class UAshenOath_InputBufferComponent* GetInputBufferComponent() const { return nullptr; }

	/** Dynamic corruption amount getter for visual syncing */
	virtual float GetCorruptionAmount() const { return 0.0f; }

private:
	UFUNCTION()
	void HandlePlayerDied();

	UFUNCTION()
	void HandlePlayerDamaged(float Amount, AActor* DamageSource);

	UFUNCTION()
	void EndDodge();

	FTimerHandle DodgeTimerHandle;

public:
	/** Apply screen-shake camera trauma */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Camera")
	void ApplyCameraTrauma(float Amount);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float NormalFOV;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float SprintFOV;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float FOVSmoothSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float TraumaDecay;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float MaxYawShake;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Camera")
	float MaxPitchShake;

protected:
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AshenOath|Combat")
	UAnimMontage* StaggerMontage;

private:
	UFUNCTION()
	void HandlePostureBroken();

	UFUNCTION()
	void HandleParryTriggered(AActor* Attacker);

	UFUNCTION()
	void ResetStagger();

private:
	float CameraTrauma;
};

