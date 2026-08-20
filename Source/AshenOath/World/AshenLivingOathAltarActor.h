// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Soul/AshenLivingOathSubsystem.h"
#include "AshenLivingOathAltarActor.generated.h"

/**
 * AAshenLivingOathAltarActor
 * In-world consecrated altar where Kaelen swears, progresses, or communes with Living Oaths.
 */
UCLASS()
class ASHENOATH_API AAshenLivingOathAltarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenLivingOathAltarActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Oath Altar")
	bool bIsAltarActive = true;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Oath Altar")
	bool SwearOathAtAltar(EAshenLivingOathType OathToSwear);
};
