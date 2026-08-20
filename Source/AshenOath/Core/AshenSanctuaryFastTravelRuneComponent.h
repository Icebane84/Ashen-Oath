// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenSanctuaryFastTravelRuneComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnFastTravelRuneActivatedSignature, FName, RuneID);

/**
 * UAshenSanctuaryFastTravelRuneComponent
 *
 * Fast travel rune component attached to world sanctuary teleporter pillars.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenSanctuaryFastTravelRuneComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenSanctuaryFastTravelRuneComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|FastTravelRune")
	bool ActivateRune();

	UFUNCTION(BlueprintPure, Category = "AshenOath|FastTravelRune")
	bool IsRuneActivated() const { return bIsActivated; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|FastTravelRune")
	FName RuneID = FName("SanctuaryRune_TarnSpire");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|FastTravelRune|Events")
	FOnFastTravelRuneActivatedSignature OnRuneActivated;

private:
	bool bIsActivated = false;
};
