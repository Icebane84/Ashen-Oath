// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulPerkNodeComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSoulPerkUnlockedSignature, FName, PerkID, float, AshSpent);

/**
 * UAshenSoulPerkNodeComponent
 *
 * Mindscape constellation perk node component.
 * Manages perk unlock status, Ash currency requirements, and prerequisite node validation.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulPerkNodeComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulPerkNodeComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SoulPerk")
	bool UnlockPerk(float PlayerAshAmount, bool bPrerequisiteMet = true);

	UFUNCTION(BlueprintPure, Category = "AshenOath|SoulPerk")
	bool IsUnlocked() const { return bIsUnlocked; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulPerk")
	FName PerkID = FName("Perk_Default");

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|SoulPerk")
	float AshUnlockCost = 150.0f;

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SoulPerk|Events")
	FOnSoulPerkUnlockedSignature OnPerkUnlocked;

private:
	bool bIsUnlocked = false;
};
