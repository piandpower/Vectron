// Some copyright should be here...

#pragma once

#include "ModuleManager.h"
#include "VectorField/VectorFieldStatic.h"
#include "Vectron.generated.h"

#define DLOG(text) if (GLog) GLog->Log(text)
#define DLOGN(num) if (GLog) GLog->Log(FString::FromInt(num))
#define DLOGF(flt) if (GLog) GLog->Log(FString::SanitizeFloat(flt))

USTRUCT()
struct FFGAContents
{
	GENERATED_USTRUCT_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FGA")
	int32 GridX;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FGA")
	int32 GridY;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FGA")
	int32 GridZ;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FGA")
	FBox Bounds;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "FGA")
	TArray<FVector> Vectors;
};

class FVectronModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command.*/
	void PluginButtonClicked();
	void OtherPluginButtonClicked();

	FFGAContents* m_escrowFga;

	AActor* m_activeActor;

	static inline FVectronModule& Get()
	{
		return FModuleManager::LoadModuleChecked< FVectronModule >("Vectron");
	}

private:

	void AddToolbarExtension(class FToolBarBuilder &);
	void AddMenuExtension(class FMenuBuilder &);

	void InjectVolumeIntoScene();
	UVectorFieldStatic* m_vectorField;

	void ExportEscorwToFile(FString);

	TSharedPtr<class FUICommandList> PluginCommands;
};