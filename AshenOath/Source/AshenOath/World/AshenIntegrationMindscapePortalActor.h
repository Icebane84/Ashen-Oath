// Copyright Phoenix Protocol / Ashen Oath. All Rights Reserved.
#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "AshenIntegrationMindscapePortalActor.generated.h"

/**
 * AAshenIntegrationMindscapePortalActor
 * 3D world portal spawned when Integration Debt reaches 100%, forcing immediate entry into the psychic Mindscape trial.
 */
UCLASS()
class ASHENOATH_API AAshenIntegrationMindscapePortalActor : public AActor
{
	GENERATED_BODY()
public:
	AAshenIntegrationMindscapePortalActor();
	virtual void BeginPlay() override;

	UPROPERTY(BlueprintReadOnly, Category = "Ashen Oath | Portal")
	bool bIsPortalOpen = false;

	UFUNCTION(BlueprintCallable, Category = "Ashen Oath | Portal")
	void OpenForcedIntegrationPortal();
};
