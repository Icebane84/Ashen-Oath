// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSoulRemnantsComponent.generated.h"

UENUM(BlueprintType)
enum class EAshenRemnantResolution : uint8
{
	ShatterForEmbers UMETA(DisplayName = "Shatter (Crafting Embers)"),
	AbsorbForLore    UMETA(DisplayName = "Absorb (Uncovers Lore, Accrues Taint)")
};

DECLARE_DYNAMIC_MULTICAST_DELEGATE_TwoParams(FOnSoulRemnantResolvedSignature, EAshenRemnantResolution, Resolution, float, EmberOrTaintAmount);

/**
 * UAshenSoulRemnantsComponent
 *
 * Moral choice component attached to defeated Ash Walker enemies. Allows player to Shatter or Absorb soul remnants.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSoulRemnantsComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSoulRemnantsComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|SoulRemnants")
	void ResolveRemnant(EAshenRemnantResolution Resolution, AActor* ResolvingActor);

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|SoulRemnants|Events")
	FOnSoulRemnantResolvedSignature OnSoulRemnantResolved;
};
