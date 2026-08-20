// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenCorruptedSanctuaryFontActor.generated.h"

/**
 * AAshenCorruptedSanctuaryFontActor
 * World shrine reacting to Kaelen's physical shadow mark seepage, unlocking ancient memory pathways when corruption >= 0.50.
 */
UCLASS()
class ASHENOATH_API AAshenCorruptedSanctuaryFontActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenCorruptedSanctuaryFontActor();
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Ashen Oath | Font")
	float ActivationRadius = 600.0f;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Font")
	bool bIsFontHarmonized = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Font")
	bool HarmonizeFont(AActor* InstigatingPlayer, float CurrentCorruption);
};
