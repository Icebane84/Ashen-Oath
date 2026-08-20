// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCReactivityDialogueToneAdapter.generated.h"

/**
 * UAshenNPCReactivityDialogueToneAdapter
 * Adjusts NPC greeting dialogue lines based on Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCReactivityDialogueToneAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCReactivityDialogueToneAdapter();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	FName GetActiveDialogueToneTag() const { return ActiveToneTag; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	FName ActiveToneTag;
};
