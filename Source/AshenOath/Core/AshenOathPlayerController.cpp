#include "AshenOathPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "Blueprint/UserWidget.h"
#include "AshenOath.h"
#include "Widgets/Input/SVirtualJoystick.h"
#include "AshenSoulConstellationSubsystem.h"
#include "AshenOath_ImprintBufferComponent.h"
#include "AshenOath_CurrencyComponent.h"
#include "AshenCheatManager.h"
#include "GameFramework/Pawn.h"

AAshenOathPlayerController::AAshenOathPlayerController()
{
	CheatClass = UAshenCheatManager::StaticClass();
}

void AAshenOathPlayerController::BeginPlay()

{
	Super::BeginPlay();

	// only spawn touch controls on local player controllers
	if (IsLocalPlayerController() && ShouldUseTouchControls())
	{
		// spawn the mobile controls widget
		MobileControlsWidget = CreateWidget<UUserWidget>(this, MobileControlsWidgetClass);

		if (MobileControlsWidget)
		{
			// add the controls to the player screen
			MobileControlsWidget->AddToPlayerScreen(0);

		} else {

			UE_LOG(LogAshenOath, Error, TEXT("Could not spawn mobile controls widget."));

		}

	}
}

void AAshenOathPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// only add IMCs for local player controllers
	if (IsLocalPlayerController())
	{
		// Add Input Mapping Contexts
		if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
		{
			for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
			{
				Subsystem->AddMappingContext(CurrentContext, 0);
			}

			// only add these IMCs if we're not using mobile touch input
			if (!ShouldUseTouchControls())
			{
				for (UInputMappingContext* CurrentContext : MobileExcludedMappingContexts)
				{
					Subsystem->AddMappingContext(CurrentContext, 0);
				}
			}
		}
	}
}

bool AAshenOathPlayerController::ShouldUseTouchControls() const
{
	return bForceTouchControls;
}

// ---------------------------------------------------------------------------
// Developer Playtest Cheats (Console Exec Commands)
// ---------------------------------------------------------------------------

void AAshenOathPlayerController::AshenAddImprint(float Weight)
{
	if (APawn* PlayerPawn = GetPawn())
	{
		if (UAshenOath_ImprintBufferComponent* Buffer = PlayerPawn->FindComponentByClass<UAshenOath_ImprintBufferComponent>())
		{
			Buffer->AddImprint(EImprintType::Combat, Weight);
			UE_LOG(LogAshenOath, Log, TEXT("Cheat AshenAddImprint: Added imprint weight %.2f"), Weight);
		}
	}
}

void AAshenOathPlayerController::AshenTriggerIntegration()
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			Kernel->InvokeIntegration(/*bForced=*/false);
			UE_LOG(LogAshenOath, Log, TEXT("Cheat AshenTriggerIntegration: Triggered integration ritual."));
		}
	}
}

void AAshenOathPlayerController::AshenAddCurrency(float Embers, float Ash)
{
	if (APawn* PlayerPawn = GetPawn())
	{
		if (UAshenOath_CurrencyComponent* Currency = PlayerPawn->FindComponentByClass<UAshenOath_CurrencyComponent>())
		{
			Currency->AddEmbers(Embers);
			Currency->AddAsh(Ash);
			UE_LOG(LogAshenOath, Log, TEXT("Cheat AshenAddCurrency: +%.0f Embers | +%.0f Ash"), Embers, Ash);
		}
	}
}

void AAshenOathPlayerController::AshenSetLens(int32 LensIndex)
{
	if (UGameInstance* GI = GetGameInstance())
	{
		if (UAshenSoulConstellationSubsystem* Kernel = GI->GetSubsystem<UAshenSoulConstellationSubsystem>())
		{
			EInterpretiveLens NewLens = static_cast<EInterpretiveLens>(FMath::Clamp(LensIndex, 0, 2));
			Kernel->FinalizeIntegration(NewLens);
			UE_LOG(LogAshenOath, Log, TEXT("Cheat AshenSetLens: Finalized integration with Lens %d"), LensIndex);
		}
	}
}

