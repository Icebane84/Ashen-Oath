// Copyright Phoenix Protocol. All rights reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenWeaponActor.h"
#include "AshenOath_EquipmentComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnWeaponEquippedSignature, AAshenWeaponActor*, EquippedWeapon);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenOath_EquipmentComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenOath_EquipmentComponent();

protected:
	virtual void BeginPlay() override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

public:
	/** Spawn and attach weapon class to owner character mesh */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Equipment")
	void EquipWeapon(TSubclassOf<AAshenWeaponActor> WeaponClass);

	/** Unequip and destroy current weapon */
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Equipment")
	void UnequipWeapon();

	/** Getters */
	UFUNCTION(BlueprintPure, Category = "AshenOath|Equipment")
	AAshenWeaponActor* GetEquippedWeapon() const { return SpawnedWeapon; }

public:
	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Equipment|Events")
	FOnWeaponEquippedSignature OnWeaponEquipped;

private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Equipment", meta = (AllowPrivateAccess = "true"))
	FName DefaultWeaponSocket;

	UPROPERTY(Transient, BlueprintReadOnly, Category = "Equipment", meta = (AllowPrivateAccess = "true"))
	AAshenWeaponActor* SpawnedWeapon;
};
