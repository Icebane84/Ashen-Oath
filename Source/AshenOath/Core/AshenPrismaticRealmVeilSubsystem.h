// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Subsystems/WorldSubsystem.h"
#include "AshenPrismaticRealmVeilSubsystem.generated.h"

UENUM(BlueprintType)
enum class EAshenWorldVeilState : uint8
{
	MaterialWorld        UMETA(DisplayName = "Material World (Standard Realm)"),
	PrismaticVoidPhase   UMETA(DisplayName = "Prismatic Void (Psychic Mirror Realm)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnVeilStateChangedSignature, EAshenWorldVeilState, NewVeilState, float, VoidDissonanceFactor);

/**
 * UAshenPrismaticRealmVeilSubsystem
 *
 * World Subsystem driving real-time phase shifting between the Material World and the Prismatic Void.
 */
UCLASS()
class ASHENOATH_API UAshenPrismaticRealmVeilSubsystem : public UWorldSubsystem
{
	GENERATED_BODY()

public:
	virtual void Initialize(FSubsystemCollectionBase& Collection) override;

	UFUNCTION(BlueprintCallable, Category = "AshenOath|PrismaticVeil")
	void ShiftWorldVeilState(EAshenWorldVeilState NewState);

	UFUNCTION(BlueprintPure, Category = "AshenOath|PrismaticVeil")
	EAshenWorldVeilState GetCurrentVeilState() const { return CurrentVeilState; }

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|PrismaticVeil|Events")
	FOnVeilStateChangedSignature OnVeilStateChanged;

private:
	EAshenWorldVeilState CurrentVeilState = EAshenWorldVeilState::MaterialWorld;
};
