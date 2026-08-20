// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenDungeonLootKeycardComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnKeycardCollectedSignature, FName, KeycardID);

/**
 * UAshenDungeonLootKeycardComponent
 *
 * Master dungeon keycard & rune key component attached to quest item pickups.
 */
UCLASS(ClassGroup=(AshenOath), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenDungeonLootKeycardComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenDungeonLootKeycardComponent();

protected:
	virtual void BeginPlay() override;

public:
	UFUNCTION(BlueprintCallable, Category = "AshenOath|Keycard")
	void CollectKeycard(AActor* CollectingActor);

	UFUNCTION(BlueprintPure, Category = "AshenOath|Keycard")
	bool IsCollected() const { return bIsCollected; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AshenOath|Keycard")
	FName KeycardID = FName("RuneKey_GreywatchGate");

	UPROPERTY(BlueprintAssignable, Category = "AshenOath|Keycard|Events")
	FOnKeycardCollectedSignature OnKeycardCollected;

private:
	bool bIsCollected = false;
};
