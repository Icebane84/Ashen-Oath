// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenNovaSanctuaryAltarActor.generated.h"

/**
 * AAshenNovaSanctuaryAltarActor
 * Sanctuary altar purifying accumulated Integration Debt and resetting psychological friction post-finisher.
 */
UCLASS()
class ASHENOATH_API AAshenNovaSanctuaryAltarActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenNovaSanctuaryAltarActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Nova")
	bool bIsAltarConsecrated = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Nova")
	bool ConsecrateNovaAltar(AActor* InstigatingPlayer);
};
