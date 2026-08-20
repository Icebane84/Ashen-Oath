// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "Soul/AshenSoulStateVector.h"
#include "AshenNPCRumorGenerationAdapterComponent.generated.h"

/**
 * UAshenNPCRumorGenerationAdapterComponent
 * Dynamically generates NPC rumor dialogue variants based on Kaelen's Corruption.
 */
UCLASS(ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class ASHENOATH_API UAshenNPCRumorGenerationAdapterComponent : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenNPCRumorGenerationAdapterComponent();

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	void OnSoulStateInvalidated(const FSoulStateVector& NewState);

	UFUNCTION(BlueprintCallable, Category = "AshenOath|World")
	FName GetActiveRumorTag() const { return ActiveRumorTag; }

private:
	UPROPERTY(VisibleAnywhere, Category = "AshenOath|World")
	FName ActiveRumorTag;
};
