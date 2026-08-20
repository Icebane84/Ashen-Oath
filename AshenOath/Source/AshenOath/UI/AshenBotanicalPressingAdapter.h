// Copyright Ashen Oath Tactical RPG. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "AshenBotanicalPressingAdapter.generated.h"

class UTexture2D;

/**
 * UAshenBotanicalPressingAdapter
 * 
 * Renders Serafina's delicate pressed silverleaf botanical illustrations
 * in the living journal canvas.
 */
UCLASS(ClassGroup=(Ashen), meta=(BlueprintSpawnableComponent))
class ASHENOATH_API UAshenBotanicalPressingAdapter : public UActorComponent
{
	GENERATED_BODY()

public:
	UAshenBotanicalPressingAdapter();

	/** Binds botanical herb texture to journal margin slot */
	UFUNCTION(BlueprintCallable, Category = "Ashen|UI|Botanical")
	void PressHerbToJournal(FName HerbId, UTexture2D* HerbTexture, float Opacity = 0.85f);

	UFUNCTION(BlueprintPure, Category = "Ashen|UI|Botanical")
	float GetHerbOpacity() const { return CurrentOpacity; }

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Botanical")
	FName ActiveHerbId;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen|UI|Botanical")
	float CurrentOpacity = 0.85f;
};
