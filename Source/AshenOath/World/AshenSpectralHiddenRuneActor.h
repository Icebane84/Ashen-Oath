// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenSpectralHiddenRuneActor.generated.h"

/**
 * AAshenSpectralHiddenRuneActor
 * World actor glowing and unlocking pathways only when illuminated by the alchemical lantern.
 */
UCLASS()
class ASHENOATH_API AAshenSpectralHiddenRuneActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenSpectralHiddenRuneActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | World")
	bool bIsRuneRevealed = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | World")
	void RevealSpectralRune();
};
